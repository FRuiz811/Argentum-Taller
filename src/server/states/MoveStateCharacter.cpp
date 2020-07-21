#include <iostream>
#include "MoveStateCharacter.h"
#include "../GameCharacter.h"
#include "StillStateCharacter.h"
#include "../Creature.h"


MoveStateCharacter::~MoveStateCharacter() = default;

MoveStateCharacter::MoveStateCharacter() : StateCharacter() {
    stateId = StateID::Move;
    direction = Direction::down;
}

void MoveStateCharacter::performTask(uint id,
                                     std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                     Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (!movement.hasStart()) {
        aCharacter->setDirection(direction);
        std::shared_ptr<Cell> newCell;
        if (board.characterCanMove(aCharacter->getActualCell(), direction)) {
            newCell = board.getNextCell(aCharacter->getActualCell(), direction);
            movement.start(board.getPointFromCell(aCharacter->getActualCell()), direction, aCharacter->getRace());
            aCharacter->getActualCell()->free();
            newCell->occupied(id);
            aCharacter->setCell(newCell);
            uint nestId = newCell->getNestId();
            if (nestId != 0 && !aCharacter->isDead()) {
                std::shared_ptr<Creature> aCreature;
                for(auto &creatureId : board.getCreaturesInNest(nestId)) {
                    aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(creatureId));
                    aCreature->notify(id);
                }
            }
        } else {
            finalized = true;
        }
    } else {
        aCharacter->setPoint(movement.doStep());
        if (movement.isOver()) {
            finalized = true;
        }
    }

}

StateID MoveStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    } else if(info.input == InputID::stopMove) {
        nextStateId = StateID::Still;
    }
    return nextStateId;
}

StateID MoveStateCharacter::getResetStateID() {
    return StateID::Move;
}

bool MoveStateCharacter::isAttacking() {
    return false;
}

bool MoveStateCharacter::isMeditating() {
    return false;
}

void MoveStateCharacter::init(InputInfo aInputInfo) {
    movement.reset();
    switch(aInputInfo.input) {
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
        default:
            direction = Direction::down;
            break;
    }
    inputInfo = aInputInfo;
    finalized = false;
}
