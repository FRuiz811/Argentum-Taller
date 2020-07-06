#include <memory>
#include "ServerProxy.h"
#include "JsonReader.h"
#include "NPCServer.h"
#include "Creature.h"
#include <cstdlib>
#include <iostream>

ServerProxy::ServerProxy() {
    std::srand((int)std::time(nullptr));
    rapidjson::Document jsonMap = JsonReader::read("json/finishedMap.json");
    rapidjson::Document jsonConfigStats = JsonReader::read("json/gameStats.json");
    tiledMap = TiledMap(jsonMap);
    gameStatsConfig = GameStatsConfig(jsonConfigStats);
    board = Board(tiledMap.getObjectLayers(),
                  tiledMap.getWidth() * tiledMap.getTileWidth(),
                  tiledMap.getHeight() * tiledMap.getTileHeight(),
                  gameStatsConfig.getNestCreatureLimit());
    addNPCs(tiledMap.getObjectLayers());
    addCreatures();

}

TiledMap& ServerProxy::getStaticMap() {
    return tiledMap;
}

PlayerInfo ServerProxy::createCharacter(RaceID race, GameClassID gameClass) {
    uint id = getNextId();
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, board.getInitialPoint()));
    board.addGameObjectPosition(id, aCharacter->getBoardPosition());
    gameObjectsContainer.addGameObject(aCharacter, id);
    return aCharacter->getPlayerInfo();
}

void ServerProxy::sendInput(InputInfo input, uint  id){
    if (input.input != InputID::nothing) {
        std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjectsContainer.getGameObject(id));
        aCharacter->receiveInput(input);
    }
}

void ServerProxy::update() {
    gameObjectsContainer.update(board, gameStatsConfig);
}

PlayerInfo ServerProxy::getUpdatedPlayerInfo(uint id) {
    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjectsContainer.getGameObject(id));
    return aCharacter->getPlayerInfo();
}

std::vector<GameObjectInfo> ServerProxy::getUpdatedGameObjectsInfo() {
    return gameObjectsContainer.getUpdatedGameObjectsInfo();
}

uint ServerProxy::getNextId() {
    return current_id++;
}

void ServerProxy::addNPCs(std::vector<ObjectLayer> objectLayers) {
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

void ServerProxy::addCreatures() {
    for (int i = 0; i < gameStatsConfig.getCreaturesLimit(); ++i) {
        generateCreature();
    }
}

void ServerProxy::generateCreature() {
    uint id = getNextId();
    uint8_t randomId = 1 + std::rand() % 4;
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

ServerProxy::~ServerProxy() = default;
