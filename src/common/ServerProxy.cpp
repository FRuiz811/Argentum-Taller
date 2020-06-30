#include <memory>
#include "ServerProxy.h"
#include "JsonReader.h"
#include "MapTransformer.h"
#include "Collider.h"
#include "NPCServer.h"
#include "ConfigFileTransformer.h"

ServerProxy::ServerProxy() {
    rapidjson::Document jsonMap = JsonReader::read("json/bigMapNPC.json");
    rapidjson::Document jsonConfigStats = JsonReader::read("json/gameStats.json");
    tiledMap = MapTransformer::transform(jsonMap);
    board = Board(tiledMap.getObjectLayers(),
                  tiledMap.getWidth() * tiledMap.getTilewidth(),
                  tiledMap.getHeight() * tiledMap.getTileheight());
    gameStatsConfig = ConfigFileTransformer::transform(jsonConfigStats);
    addNPCs(tiledMap.getObjectLayers());
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

ServerProxy::~ServerProxy() = default;



//PlayerInfo ServerProxy::updateModel() {
//    std::shared_ptr<GameCharacter> aCharacter =  std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(current_id - 1));
//    while(!this->queueInputs.empty()) {
//        InputInfo inputInfo = this->queueInputs.pop();
//        switch(inputInfo.input) {
//            case InputID::nothing:
//                break;
//            case InputID::up:
//                aCharacter->move(Direction::up, gameObjects, collisionObjects);
//                break;
//            case InputID::down:
//                aCharacter->move(Direction::down, gameObjects, collisionObjects);
//                break;
//            case InputID::right:
//                aCharacter->move(Direction::right, gameObjects, collisionObjects);
//                break;
//            case InputID::left:
//                aCharacter->move(Direction::left, gameObjects, collisionObjects);
//                break;
//            case InputID::stopMove:
//                break;
//        }
//    }
//    return aCharacter->getPlayerInfo();
//}
