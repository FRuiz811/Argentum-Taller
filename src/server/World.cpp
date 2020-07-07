#include "World.h"
#include "../common/JsonReader.h"
#include "NPCServer.h"
#include "../common/Random.h"
#include "Creature.h"
#include <iostream>

#define GAMELOOPTIME 1000000/30.0

World::World(GameStatsConfig& configuration) : gameStatsConfig(configuration), 
    current_id(0), keepTalking(true) {
    rapidjson::Document jsonMap = JsonReader::read("json/finishedMap.json");
    this->map = TiledMap(jsonMap);
    this->board = Board(map.getObjectLayers(),
                  map.getWidth() * map.getTileWidth(),
                  map.getHeight() * map.getTileHeight(),
                  gameStatsConfig.getNestCreatureLimit());
    addNPCs(map.getObjectLayers());
    addCreatures();
}

uint World::getNextId() {
    uint id = this->current_id;
    this->current_id++;
    return id;
}

std::shared_ptr<GameCharacter> World::createCharacter(RaceID race, GameClassID gameClass) {
    std::unique_lock<std::mutex> lock(m);
    uint id = getNextId();
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, board.getInitialPoint()));
    board.addGameObjectPosition(id, aCharacter->getBoardPosition());
    gameObjectsContainer.addGameObject(aCharacter, id);
    return aCharacter;
}

void World::run() {
    Chrono chrono;
    double initLoop, endLoop, sleep;
    while (keepTalking) {
        initLoop = chrono.lap();
        update();
        for (auto &aPlayer : players) {
            aPlayer.second->update(getUpdatedGameObjects());
        }
        clearFinishedPlayers();
        endLoop = chrono.lap();
        sleep = GAMELOOPTIME - (endLoop - initLoop);
        if (sleep > 0)
            usleep(sleep);
    }
}

void World::addCreatures() {
    for (int i = 0; i < gameStatsConfig.getCreaturesLimit(); ++i) {
        generateCreature();
    }
}

void World::generateCreature() {
    uint id = getNextId();
    uint8_t randomId = Random::get(1, 4);
    std::cout << std::to_string(randomId) << std::endl;
    NestPoint& aNestPoint = board.getAvailableNestPoint();
    Point initialPoint = board.getInitialPointInNest(aNestPoint);
    if (initialPoint.x == 0.0 && initialPoint.y == 0.0) {
        std::cout << "cannot create creature" << std::endl;
    } else {
        aNestPoint.addCreature(id);
        std::shared_ptr<Creature> aCreature(new Creature(id, CreatureID(randomId), aNestPoint.getNestId(), initialPoint));
        board.addGameObjectPosition(id, aCreature->getBoardPosition());
        gameObjectsContainer.addGameObject(aCreature, id);
    }
}


TiledMap& World::getStaticMap() {
    return this->map;
}

void World::addNPCs(std::vector<ObjectLayer> objectLayers) {
    for (auto &anObjectLayer : objectLayers) {
        if (anObjectLayer.getName() == "NPC") {
            for (StaticObject &aNPCObject : anObjectLayer.getObjects()) {
                uint id = getNextId();
                std::shared_ptr<NPCServer> aNPC(new NPCServer(id, aNPCObject.getPosition().getPoint(), aNPCObject.getName()));
                board.addGameObjectPosition(id, aNPC->getBoardPosition());
                gameObjectsContainer.addGameObject(aNPC, id);
            }
        }
    }
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
    gameObjectsContainer.update(board, gameStatsConfig);
}

std::vector<GameObjectInfo> World::getUpdatedGameObjects() {
    return gameObjectsContainer.getUpdatedGameObjectsInfo();
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
            gameObjectsContainer.deleteGameObject((*iter).first);
            board.deleteGameObjectPosition((*iter).first);
            delete (*iter).second;
            iter = this->players.erase(iter);
        } else {
            iter++;
        }
    }
}

World::~World() = default;
