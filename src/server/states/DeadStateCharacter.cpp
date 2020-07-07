#include "DeadStateCharacter.h"
#include "../GameCharacter.h"

DeadStateCharacter::~DeadStateCharacter() = default;

DeadStateCharacter::DeadStateCharacter() {
    stateId = CharacterStateID::Dead;
}

void DeadStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                     Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    BoardPosition boardPosition = aCharacter->getBoardPosition();
    if (movement.hasStart()) {
        Position newPosition = movement.doStep();
        if (!board.checkCollisions(boardPosition, newPosition, aCharacter->getId())) {
            boardPosition.setPosition(newPosition);
        } else {
            movement.stop();
        }
        if (movement.isOver()) {
            canTakeAnotherAction = true;
        }
    }
    if (aCharacter->hasAnInputInfo() && canTakeAnotherAction) {
        InputInfo info =aCharacter->getNextInputInfo();
        switch (info.input) {
            case InputID::stopMove:
                movement.reset();
            case InputID::up:
                movement.start(boardPosition.getPosition(), Direction::up, gameStatsConfig, aCharacter->getRace());
                aCharacter->setDirection(direction);
                canTakeAnotherAction = false;
            case InputID::down:
                movement.start(boardPosition.getPosition(), Direction::down, gameStatsConfig, aCharacter->getRace());
                aCharacter->setDirection(direction);
                canTakeAnotherAction = false;
            case InputID::right:
                movement.start(boardPosition.getPosition(), Direction::down, gameStatsConfig, aCharacter->getRace());
                aCharacter->setDirection(direction);
                canTakeAnotherAction = false;
            case InputID::left:
                movement.start(boardPosition.getPosition(), Direction::down, gameStatsConfig, aCharacter->getRace());
                aCharacter->setDirection(direction);
                canTakeAnotherAction = false;
            default:
                movement.start(boardPosition.getPosition(), direction, gameStatsConfig, aCharacter->getRace());
                canTakeAnotherAction = false;
        }
    }

}

void DeadStateCharacter::setNextState(InputInfo info) {

}

void DeadStateCharacter::resetState() {

}

bool DeadStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool DeadStateCharacter::isAttacking() {
    return false;
}
