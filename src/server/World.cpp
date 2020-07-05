#include "World.h"
#include "../common/JsonReader.h"
#include "../common/NPCServer.h"
#include "../common/Creature.h"
#include "../common/Chrono.h"
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
    std::srand((int)std::time(nullptr));
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
    this->gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCharacter));
    return aCharacter;
}

void World::run() {
    Chrono chrono;
    double initLoop, endLoop, sleep;
    while (keepTalking) {
        initLoop = chrono.lap();
        update();
        for (auto &aPlayer : players) {
            aPlayer->update(getUpdatedGameObjects());
        }
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
    uint8_t randomId = 1 + std::rand() % 4;
    std::shared_ptr<Creature> aCreature(new Creature(id, CreatureID(randomId), board.getNextAvailableNestPoint()));
    gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCreature));
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
                gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aNPC));
            }
        }
    }
}

void World::stop() {
    this->keepTalking = false;
}

void World::update() {
    for (auto& gameObjectPair : gameObjects) {
        gameObjectPair.second->update(gameObjects, board, gameStatsConfig);
    }
}

std::vector<GameObjectInfo> World::getUpdatedGameObjects() {
    std::vector<GameObjectInfo> gameObjectsInfo;
    for (auto& gameObjectPair : gameObjects) {
        gameObjectsInfo.push_back(gameObjectPair.second->getGameObjectInfo());
    }
    return gameObjectsInfo;
}

void World::addPlayer(ThPlayer *aPlayer) {
    aPlayer->start();
    players.push_back(aPlayer);
    clearFinishedPlayers();
}

void World::clearFinishedPlayers() {
    std::vector<ThPlayer*>::iterator iter;
    iter = this->players.begin();
    while (iter != this->players.end()){
        if ((*iter)->is_alive()){
            (*iter)->join();
            iter = this->players.erase(iter);
        } else {
            iter++;
        }
    }
}

World::~World() = default;
