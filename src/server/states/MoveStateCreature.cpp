#include <iostream>
#include "MoveStateCreature.h"
#include "StillStateCreature.h"
#include "../Creature.h"

MoveStateCreature::~MoveStateCreature() = default;

MoveStateCreature::MoveStateCreature() : StateCreature(){
    stateId = StateID::Move;
    direction = Direction::down;
}

void MoveStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {
    std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
    if (!movement.hasStart()) {
        std::shared_ptr<Cell> newCell;
        aCreature->setDirection(direction);
        if (board.creatureCanMove(aCreature->getActualCell(), direction)) {
            newCell = board.getNextCell(aCreature->getActualCell(), direction);
            movement.start(board.getPointFromCell(aCreature->getActualCell()), direction, aCreature->getCreatureId());
            aCreature->getActualCell()->free();
            newCell->occupied(id);
            aCreature->setCell(newCell);
        } else {
            finalized = true;
        }
    } else {
        aCreature->setPoint(movement.doStep());
        if (movement.isOver()) {
            finalized = true;
        }
    }
}

bool MoveStateCreature::isOnPursuit(uint pursuitId) {
    return false;
}

bool MoveStateCreature::isAttacking() {
    return false;
}

StateID MoveStateCreature::getNextStateID(InputInfo info) {
    return StateID::Move;
}

StateID MoveStateCreature::getResetStateID() {
    return StateID::Move;
}

void MoveStateCreature::init(InputInfo aInputInfo) {
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
            direction = Direction::up;
            break;
    }
}
