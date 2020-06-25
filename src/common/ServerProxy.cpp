#include <memory>
#include "ServerProxy.h"
#include "JsonReader.h"
#include "MapTransformer.h"
#include "Collider.h"
#include "../client/Exception.h"
#include "NPC.h"

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
        } else if (anObjectLayer.getName() == "NPC") {
            for (StaticObject& aNPCObject : anObjectLayer.getObjects()) {
                uint id = getNextId();
                std::shared_ptr<GameObject> aNPC(new NPC(id, aNPCObject.getPosition().getPoint(), aNPCObject.getName()));
                gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(getNextId(), aNPC));
            }
        }
    }
}

ServerProxy::ServerProxy() : initialPoint(1125, 550) {
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

bool ServerProxy::characterMove(uint id, int direction) {
    bool canMove = true;
    auto& aCharacter = (gameObjects.at(id));
    Position newPosition = aCharacter->getPosition();
    switch(direction) {
        case 0:
            newPosition.setY(newPosition.getTop() - 15);
            break;
        case 1:
            newPosition.setY(newPosition.getTop() + 15);
            break;
        case 2:
            newPosition.setX(newPosition.getLeft() - 15);
            break;
        case 3:
            newPosition.setX(newPosition.getLeft() + 15);
            break;
        default:
            throw Exception("Invalid Direction");
    }
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkCollision(newPosition, collisionObject.getPosition())) {
            canMove = false;
            break;
        }
    }
    for (auto& gameObject : gameObjects) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(newPosition, gameObject.second->getPosition())) {
            canMove = false;
            break;
        }
    }
    if (canMove) {
        aCharacter->setPosition(newPosition);
    }
    return canMove;
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
