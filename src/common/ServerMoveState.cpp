#include <iostream>
#include "ServerMoveState.h"
#include "Collider.h"
#include "GameCharacter.h"
#include "ServerStillState.h"

ServerMoveState::~ServerMoveState() = default;

ServerMoveState::ServerMoveState(const InputInfo &info) : State(info) {
    switch(info.input) {
        case InputID::up:
            direction = Direction::up;
            break;
        case InputID::down:
            direction = Direction::down;
            break;
        case InputID::left:
            direction = Direction::left;
            break;
        case InputID::right:
            direction = Direction::right;
            break;
    }
}

void ServerMoveState::performTask(uint id,
        std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
        Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (amountMovements == 0) {
        float timeInSeconds = gameStatsConfig.getTimeInSeconds(aCharacter->getRace(), distance);
        amountMovements = (distance/timeInSeconds);
        std::cout << amountMovements << std::endl;
        aCharacter->setDirection(direction);
    }
    Point newPoint = aCharacter->getPosition().getPoint();
    switch(direction) {
        case Direction::up:
            newPoint.y -= distance/amountMovements;
            break;
        case Direction::down:
            newPoint.y += distance/amountMovements;
            break;
        case Direction::left:
            newPoint.x -= distance/amountMovements;
            break;
        case Direction::right:
            newPoint.x += distance/amountMovements;
            break;
    }
    Position newPosition(newPoint, aCharacter->getPosition().getWidth(), aCharacter->getPosition().getHeight());
    bool isColliding = false;
    for (auto& gameObject : gameObjects) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(newPosition, gameObject.second->getPosition())) {
            isColliding = true;
            break;
        }
    }
    if (!isColliding && !board.checkCollisions(newPosition, aCharacter->getId())) {
        aCharacter->setPosition(newPosition);
    } else {
        finalized = true;
    }
    actualMovement++;
    if (actualMovement >= amountMovements) {
        finalized = true;
    }
}

void ServerMoveState::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new ServerMoveState(info));
    } else {
        nextState = std::unique_ptr<State>(new ServerMoveState(info));
    }
}

void ServerMoveState::resetState() {
    nextState = std::unique_ptr<State>(new ServerStillState(inputInfo));
}

