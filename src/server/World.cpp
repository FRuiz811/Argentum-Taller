#include "World.h"
#include "../common/JsonReader.h"
#include "NPCServer.h"
#include "../common/Random.h"
#include "Creature.h"
#include "ObjectItem.h"
#include <iostream>

#define GAMELOOPTIME 1000000/45.0

World::World(GameStatsConfig& configuration) : gameStatsConfig(configuration), 
    current_id(1), keepTalking(true) {
    std::string path(CONFIG_DIR+std::string("/finishedMap.json"));
    rapidjson::Document jsonMap = JsonReader::read(path);
    this->banker = Banker::getInstance();
    this->merchant = Merchant::getInstance();
    this->merchant->init(GameStatsConfig::getItems());
    this->priest = Priest::getInstance();
    this->priest->init(GameStatsConfig::getItems());
    this->merchant->init(GameStatsConfig::getItems());
    this->priest->init(GameStatsConfig::getItems());
    this->map = TiledMap(jsonMap);
    this->board = Board(map, GameStatsConfig::getNestCreatureLimit());
    addNPCs(map.getObjectLayers());
    addCreatures();
}

uint World::getNextId() {
    return current_id++;
}

std::shared_ptr<GameCharacter> World::createCharacter(RaceID race, GameClassID gameClass) {
    std::unique_lock<std::mutex> lock(m);
    uint id = getNextId();
    std::shared_ptr<Cell> initialCell = board.getInitialCell();
    initialCell->occupied(id);
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, initialCell, board.getPointFromCell(initialCell)));
    gameObjectsContainer.addGameObject(aCharacter, id);
    return aCharacter;
}

void World::addNPCs(std::vector<ObjectLayer> objectLayers) {
    for (auto &anObjectLayer : objectLayers) {
        if (anObjectLayer.getName() == "NPC") {
            std::shared_ptr<Cell> aCell;
            for (StaticObject &aNPCObject : anObjectLayer.getObjects()) {
                uint id = getNextId();
                aCell = board.getCellFromPoint(aNPCObject.getTopLeft());
                aCell->occupied(id);
                std::shared_ptr<NPCServer> aNPC(new NPCServer(id, aNPCObject.getName(), board.getPointFromCell(aCell), aCell));
                gameObjectsContainer.addGameObject(aNPC, id);
            }
        }
    }
}

void World::addCreatures() {
    for (int i = 0; i < GameStatsConfig::getCreaturesLimit(); ++i) {
        generateCreature();
    }
}

void World::generateCreature() {
    uint id = getNextId();
    uint8_t randomId = Random::get(1, 4);
    try {
        Nest& aNest = board.getAvailableNest();
        std::shared_ptr<Cell> initialCell = board.getInitialCellInNest(aNest);
        initialCell->occupied(id);
        aNest.addCreature(id);
        std::shared_ptr<Creature> aCreature(new Creature(id, CreatureID(randomId), initialCell, board.getPointFromCell(initialCell)));
        gameObjectsContainer.addGameObject(aCreature, id);
    } catch (Exception& e) {
        std::cout << "Cannot create creature" << std::endl;
    }

}

void World::generateItem(const DropItem& dropItem, const std::shared_ptr<Cell>& initialCell) {
    uint id = getNextId();
    std::shared_ptr<ObjectItem> aObjectItem(new ObjectItem(id, board.getPointFromCell(initialCell), initialCell, dropItem));
    initialCell->setItemId(id);
    gameObjectsContainer.addGameObject(aObjectItem, id);
    std::cout << "Item created -- ID: " << id << std::endl;
}


void World::run() {
    Chrono chrono;
    double initLoop, endLoop, sleep;
    int amountCreaturesDiff;
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    while (keepTalking) {
        initLoop = chrono.lap();
        amountCreaturesDiff = GameStatsConfig::getCreaturesLimit() - board.getAmountCreatures();
        if (amountCreaturesDiff > 0) {
            generateCreature();
        }
        update();
        clearFinishedPlayers();
        for (auto &aPlayer : players) {
            gameObjects = gameObjectsContainer.getUpdatedGameObjects();
            aPlayer.second->update(WorldInfo(gameObjects, aPlayer.first));
        }
        checkDrops();
        removeCreaturesAndItems();
        endLoop = chrono.lap();
        sleep = GAMELOOPTIME - (endLoop - initLoop);
        if (sleep > 0)
            usleep(sleep);
    }
}

TiledMap& World::getStaticMap() {
    return this->map;
}

void World::stop() {
    this->keepTalking = false;
    for (auto & player : this->players) {
		player.second->stop();
        player.second->join();
        delete player.second;
    }
}

void World::update() {
    gameObjectsContainer.update(board);
}

void World::addPlayer(ThPlayer *aPlayer,uint id) {
    aPlayer->start();
    players.insert({id,aPlayer});
}

void World::clearFinishedPlayers() {
    auto iter = this->players.begin();
    while (iter != this->players.end()) {
        if (!(*iter).second->is_alive()) {
            (*iter).second->join();
            gameObjectsContainer.deleteGameObject((*iter).first, board);
            delete (*iter).second;
            iter = this->players.erase(iter);
        } else {
            iter++;
        }
    }
}

void World::removeCreaturesAndItems() {
    gameObjectsContainer.removeCreaturesAndItems(board);
}

void World::checkDrops() {
    for (auto &aGameObject : gameObjectsContainer.getUpdatedGameObjects()) {
        if (aGameObject->canDropsItems()) {
            for (auto &dropItem : aGameObject->getDrop()) {
                generateItem(dropItem, board.getNextEmptyCell(aGameObject->getActualCell()));
            }
        }
    }
}

World::~World() {
    delete priest;
    delete merchant;
    delete banker;
}

