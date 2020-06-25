#include <memory>
#include "ServerProxy.h"
#include "JsonReader.h"
#include "MapTransformer.h"
#include "Collider.h"
#include "../client/Exception.h"
#include "NPCServer.h"

void ServerProxy::fillCollisionsObjects(std::vector<ObjectLayer> objectLayers) {
    for (auto&& anObjectLayer : objectLayers) {
        if (anObjectLayer.getName() == "cities") {
            for (StaticObject& aCity : anObjectLayer.getObjects()) {
                cities.push_back(aCity);
            }
        } else if (anObjectLayer.getName() == "collisionObjects") {
            for (StaticObject& aCollisionObject : anObjectLayer.getObjects()) {
                collisionObjects.push_back(aCollisionObject);
            }
        } else if (anObjectLayer.getName() == "NPCServer") {
            for (StaticObject& aNPCObject : anObjectLayer.getObjects()) {
                uint id = getNextId();
                std::shared_ptr<GameObject> aNPC(new NPCServer(id, aNPCObject.getPosition().getPoint(), aNPCObject.getName()));
                gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(getNextId(), aNPC));
            }
        }
    }
}

ServerProxy::ServerProxy() : queueInputs(), initialPoint(1125, 550) {
    current_id = 0;
    rapidjson::Document jsonMap = JsonReader::read("json/bigMapNPC.json");
    tiledMap = MapTransformer::transform(jsonMap);
    fillCollisionsObjects(tiledMap.getObjectLayers());
    this->width = tiledMap.getWidth() * tiledMap.getTilewidth();
    this->heigth = tiledMap.getHeight() * tiledMap.getTileheight();
}

TiledMap& ServerProxy::getStaticMap() {
    return tiledMap;
}


PlayerInfo ServerProxy::createCharacter(int race, int gameClass) {
    uint id = getNextId();
    std::shared_ptr<GameCharacter> aCharacter(new GameCharacter(id, race, gameClass, initialPoint));
    this->gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aCharacter));
    return aCharacter->getPlayerInfo();
}

unsigned int ServerProxy::getNextId() {
    return current_id++;
}

PlayerInfo ServerProxy::updateModel() {
    std::shared_ptr<GameCharacter> aCharacter =  std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(current_id - 1));
    while(!this->queueInputs.empty()) {
        InputInfo inputInfo = this->queueInputs.pop();
        switch(inputInfo.input) {
            case InputID::nothing:
                break;
            case InputID::up:
                aCharacter->move(Direction::up, gameObjects, collisionObjects);
                break;
            case InputID::down:
                aCharacter->move(Direction::down, gameObjects, collisionObjects);
                break;
            case InputID::right:
                aCharacter->move(Direction::right, gameObjects, collisionObjects);
                break;
            case InputID::left:
                aCharacter->move(Direction::left, gameObjects, collisionObjects);
                break;
            case InputID::stopMove:
                break;
        }
    }
    return aCharacter->getPlayerInfo();
}

void ServerProxy::sendInput(InputInfo input) {
    if (input.input != InputID::nothing)
        this->queueInputs.push(input);
}


//std::vector<GameObjectInfo> ServerProxy::getUpdatedGameObjects() {
//    std::vector<GameObjectInfo> gameObjectsInfo;
//    for (auto& gameObjectPair : gameObjects) {
//        gameObjectsInfo.push_back(gameObjectPair.second->getGameObjectInfo());
//    }
//    return gameObjectsInfo;
//}

void ServerProxy::update() {
    for (auto& gameObjectPair : gameObjects) {
        gameObjectPair.second->update();
    }
}

ServerProxy::~ServerProxy() = default;
