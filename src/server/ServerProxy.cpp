#include "ServerProxy.h"
#include "JsonReader.h"
#include "MapTransformer.h"
#include "Collider.h"

void ServerProxy::fillCollisionsObjects(const std::vector<ObjectLayer> &objectLayers) {
    for (auto& anObjectLayer : objectLayers) {
        if ( anObjectLayer.getName() == "cities") {
            for (auto& aCity : anObjectLayer.getObjects()) {
                cities.push_back(std::move(aCity));
            }
        } else if (anObjectLayer.getName() == "collisionObjects") {
            for (auto& aCollisionObject : anObjectLayer.getObjects()) {
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

uint ServerProxy::createCharacter(int race, int gameClass) {
    Position position(20, 30, 32, 32);
    Character aCharacter(race, gameClass, std::move(position));
    uint id = getNextId();
    gameObjects.insert(std::pair<int, GameObject>(id, std::move(aCharacter)));
    return id;
}

unsigned int ServerProxy::getNextId() {
    return current_id++;
}

std::unordered_map<uint, GameObject,
std::hash<uint>> ServerProxy::getGameObjects() {
    return gameObjects;
}

bool ServerProxy::characterMove(uint id) {
    bool canMove = true;
    auto& aCharacter = (Character&)(gameObjects.at(id));
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkCollision(aCharacter.getPosition(), collisionObject.getPosition())) {
            canMove = false;
            break;
        }
    }
    for (auto& gameObject : gameObjects) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(aCharacter.getPosition(), gameObject.second.getPosition())) {
            canMove = false;
            break;
        }
    }
    return canMove;
}

ServerProxy::~ServerProxy() = default;
