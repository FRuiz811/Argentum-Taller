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
    std::shared_ptr<Cell> characterCell = aCharacter->getActualCell();
    if (!movement.hasStart()) {
        if (aCharacter->hasAnInputInfo()) {
            inputInfo = aCharacter->getNextInputInfo();
            switch (inputInfo.input) {
                case InputID::stopMove:
                    movementAction = false;
                    break;
                case InputID::up:
                    movementAction = true;
                    direction = Direction::up;
                    break;
                case InputID::down:
                    movementAction = true;
                    direction = Direction::down;
                    break;
                case InputID::right:
                    movementAction = true;
                    direction = Direction::right;
                    break;
                case InputID::left:
                    movementAction = true;
                    direction = Direction::left;
                    break;
            }
        }
        if (movementAction) {
            aCharacter->setDirection(direction);
            if (board.characterCanMove(aCharacter->getActualCell(), direction)) {
                std::shared_ptr<Cell> newCell = board.getNextCell(characterCell, direction);
                movement.start(board.getPointFromCell(characterCell), direction, gameStatsConfig,
                               aCharacter->getRace());
                characterCell->free();
                newCell->occupied(id);
                aCharacter->setCell(newCell);
                canTakeAnotherAction = false;
            }
        }
    } else {
        aCharacter->setPoint(movement.doStep());
        if (movement.isOver()) {
            movement.reset();
            canTakeAnotherAction = true;
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
