#include "World.h"
#include "../common/JsonReader.h"
#include "../common/ConfigFileTransformer.h"
#include "../common/NPCServer.h"
#include "../common/GameCharacter.h"
#include <iostream>

World::World(GameStatsConfig& configuration) : gameStatsConfig(configuration), 
    current_id(0), inputQueue(false), keepTalking(true) {
    rapidjson::Document jsonMap = JsonReader::read("json/bigMapNPC.json");
    this->map = TiledMap(jsonMap);
    this->board = Board(map.getObjectLayers(),
                  map.getWidth() * map.getTileWidth(),
                  map.getHeight() * map.getTileHeight());
    addNPCs(map.getObjectLayers());
}


uint World::getNextId() {
    uint id = this->current_id;
    this->current_id++;
    return id;
}

PlayerInfo World::createCharacter(RaceID race, GameClassID gameClass) {
    std::unique_lock<std::mutex> lock(m);
    uint id = getNextId();
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, board.getInitialPoint()));
    this->gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCharacter));
    return aCharacter->getPlayerInfo();
}

void World::run(){

}


TiledMap& World::getStaticMap() {
    return this->map;
}

InputQueue& World::getInputQueue() {
    return this->inputQueue;
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

World::~World() {}
