#include "DeadStateCharacter.h"
#include "../GameCharacter.h"

DeadStateCharacter::~DeadStateCharacter() = default;

DeadStateCharacter::DeadStateCharacter() {
    stateId = CharacterStateID::Dead;
    direction = Direction::down;
    InputInfo info;
    info.input = InputID::nothing;
    inputInfo = info;
}

void DeadStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                     Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    BoardPosition& boardPosition = aCharacter->getBoardPosition();
    if (aCharacter->hasAnInputInfo() && canTakeAnotherAction) {
        inputInfo = aCharacter->getNextInputInfo();
        switch (inputInfo.input) {
            case InputID::stopMove:
                movement.reset();
                break;
            case InputID::up:
                canTakeAnotherAction = false;
                movement.start(boardPosition.getPosition(), Direction::up, gameStatsConfig,
                               aCharacter->getRace());
                direction = Direction::up;
                aCharacter->setDirection(direction);
                break;

            case InputID::down:
                canTakeAnotherAction = false;
                movement.start(boardPosition.getPosition(), Direction::down, gameStatsConfig,
                               aCharacter->getRace());
                direction = Direction::down;
                aCharacter->setDirection(direction);
                break;
            case InputID::right:
                canTakeAnotherAction = false;
                movement.start(boardPosition.getPosition(), Direction::right, gameStatsConfig,
                               aCharacter->getRace());
                direction = Direction::right;
                aCharacter->setDirection(direction);
                break;
            case InputID::left:
                canTakeAnotherAction = false;
                movement.start(boardPosition.getPosition(), Direction::left, gameStatsConfig,
                               aCharacter->getRace());
                direction = Direction::left;
                aCharacter->setDirection(direction);
                break;
        }
    } else {
        if (!movement.hasStart()) {
            if (inputInfo.input == InputID::up || inputInfo.input == InputID::down ||
                inputInfo.input == InputID::left || inputInfo.input == InputID::right) {

                movement.start(boardPosition.getPosition(), direction, gameStatsConfig, aCharacter->getRace());
                canTakeAnotherAction = false;
            }
        } else {
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
