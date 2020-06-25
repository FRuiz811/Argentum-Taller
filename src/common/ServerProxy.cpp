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
    this->player = PlayerInfo(id, position.getLeft(), position.getTop(), 100, 100, 100, "ht02|h03|b04|s00|w03",Direction::down);
    return this->player;
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
                characterMove(player.getId(),Direction::up);
                break;
            case InputID::down:
                characterMove(player.getId(),Direction::down);
                break;
            case InputID::right:
                characterMove(player.getId(),Direction::right);
                break;
            case InputID::left:
                characterMove(player.getId(),Direction::left);
                break;
            case InputID::stopMove:
                break;
        }
    }
    return this->player;
}



bool ServerProxy::characterMove(uint id, Direction direction) {
    bool canMove = true;
    auto& aCharacter = (gameObjects.at(id));
    Position newPosition = aCharacter.getPosition();
    switch(direction) {
        case Direction::up:
            newPosition.setY(newPosition.getTop() - 15);
            break;
        case Direction::down:
            newPosition.setY(newPosition.getTop() + 15);
            break;
        case Direction::left:
            newPosition.setX(newPosition.getLeft() - 15);
            break;
        case Direction::right:
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
        this->player.changeDirection(direction);
    }
    return canMove;
}

void ServerProxy::sendInput(InputInfo input) {
    if (input.input != InputID::nothing)
        this->queueInputs.push(input);
}

ServerProxy::~ServerProxy() = default;
