#include "ServerProxy.h"
#include "JsonReader.h"
#include "MapTransformer.h"
#include "Collider.h"
#include "../client/Exception.h"

void ServerProxy::fillCollisionsObjects(std::vector<ObjectLayer> objectLayers) {
    for (auto&& anObjectLayer : objectLayers) {
        if (anObjectLayer.getName() == "cities") {
            for (auto&& aCity : anObjectLayer.getObjects()) {
                cities.push_back(std::move(aCity));
            }
        } else if (anObjectLayer.getName() == "collisionObjects") {
            for (auto&& aCollisionObject : anObjectLayer.getObjects()) {
                collisionObjects.push_back(std::move(aCollisionObject));
            }
        }
    }
}

ServerProxy::ServerProxy() {
    current_id = 0;
    rapidjson::Document jsonMap = JsonReader::read("json/bigMapCollisions.json");
    tiledMap = MapTransformer::transform(jsonMap);
    fillCollisionsObjects(tiledMap.getObjectLayers());
    this->width = tiledMap.getWidth() * tiledMap.getTilewidth();
    this->heigth = tiledMap.getHeight() * tiledMap.getTileheight();
}

TiledMap& ServerProxy::getStaticMap() {
    return tiledMap;
}

PlayerInfo ServerProxy::createCharacter(int race, int gameClass) {
    Position position(1125, 550, 25, 60);
    GameCharacter aCharacter(race, gameClass, position);
    uint id = getNextId();
    gameObjects.insert(std::pair<int, GameObject&&>(id, std::move(aCharacter)));
    return PlayerInfo(id, position.getLeft(), position.getTop(), 100, 100, 100, "ht:01|h:01|b:01|s01|w01");
}

uint ServerProxy::getNextId() {
    return current_id++;
}

bool ServerProxy::characterMove(uint id, int direction) {
    bool canMove = true;
    auto& aCharacter = (gameObjects.at(id));
    Position newPosition = aCharacter.getPosition();
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
        if (Collider::checkCollision(newPosition, gameObject.second.getPosition())) {
            canMove = false;
            break;
        }
    }
    if (canMove) {
        aCharacter.setPosition(newPosition);
    }
    return canMove;
}

ServerProxy::~ServerProxy() = default;
