#include <memory>
#include "ServerProxy.h"
#include "JsonReader.h"
#include "NPCServer.h"
#include "Creature.h"
#include <cstdlib>
#include <ctime>

ServerProxy::ServerProxy() {
    rapidjson::Document jsonMap = JsonReader::read("json/finishedMap.json");
    rapidjson::Document jsonConfigStats = JsonReader::read("json/gameStats.json");
    tiledMap = TiledMap(jsonMap);
    gameStatsConfig = GameStatsConfig(jsonConfigStats);
    board = Board(tiledMap.getObjectLayers(),
                  tiledMap.getWidth() * tiledMap.getTileWidth(),
                  tiledMap.getHeight() * tiledMap.getTileHeight(),
                  gameStatsConfig.getNestCreatureLimit());
    addNPCs(tiledMap.getObjectLayers());
    std::srand((int)std::time(nullptr));
    addCreatures();
}

TiledMap& ServerProxy::getStaticMap() {
    return tiledMap;
}

PlayerInfo ServerProxy::createCharacter(RaceID race, GameClassID gameClass) {
    uint id = getNextId();
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, board.getInitialPoint()));
    this->gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCharacter));
    return aCharacter->getPlayerInfo();
}

void ServerProxy::sendInput(InputInfo input, uint  id){
    if (input.input != InputID::nothing) {
        std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
        aCharacter->receiveInput(input);
    }
}

void ServerProxy::update() {
    for (auto& gameObjectPair : gameObjects) {
        gameObjectPair.second->update(gameObjects, board, gameStatsConfig);
    }
}

PlayerInfo ServerProxy::getUpdatedPlayerInfo(uint id) {
    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    return aCharacter->getPlayerInfo();
}

std::vector<GameObjectInfo> ServerProxy::getUpdatedGameObjects() {
    std::vector<GameObjectInfo> gameObjectsInfo;
    for (auto& gameObjectPair : gameObjects) {
        gameObjectsInfo.push_back(gameObjectPair.second->getGameObjectInfo());
    }
    return gameObjectsInfo;
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
                gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aNPC));
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
    std::shared_ptr<Creature> aCreature(new Creature(id, CreatureID(randomId), board.getNextAvailableNestPoint()));
    gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCreature));
}

ServerProxy::~ServerProxy() = default;
