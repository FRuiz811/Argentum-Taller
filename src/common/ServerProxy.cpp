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

ServerProxy::ServerProxy() : queueInputs() {
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
    this->player = PlayerInfo(id, position.getLeft(), position.getTop(), 100, 100, 100, "ht:01|h:01|b:01|s01|w01");
    return std::move(this->player);
}

uint ServerProxy::getNextId() {
    return current_id++;
}

PlayerInfo ServerProxy::updateModel() {
    while(!this->queueInputs.empty()) {
        InputInfo inputInfo = this->queueInputs.pop();
        switch(inputInfo.input) {
            case InputID::nothing:
                break;
            case InputID::up:
                characterMove(player.getId(),0);
                break;
            case InputID::down:
                characterMove(player.getId(),1);
                break;
            case InputID::right:
                characterMove(player.getId(),3);
                break;
            case InputID::left:
                characterMove(player.getId(),2);
                break;
            case InputID::stopMove:
                break;
        }
    }
    return std::move(this->player);
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
        this->player.setX(newPosition.getLeft());
        this->player.setY(newPosition.getTop());
    }
    return canMove;
}

void ServerProxy::sendInput(InputInfo input) {
    this->queueInputs.push(input);
}

ServerProxy::~ServerProxy() = default;
