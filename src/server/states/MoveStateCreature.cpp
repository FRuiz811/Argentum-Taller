#include <iostream>
#include "MoveStateCreature.h"
#include "StillStateCreature.h"
#include "../Creature.h"

MoveStateCreature::~MoveStateCreature() = default;

MoveStateCreature::MoveStateCreature(InputInfo info) : State(info),
    direction(Direction::down), movement(){
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
        default:
            direction = Direction::up;
            break;
    }
    stateId = CharacterStateID::Move;
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

void MoveStateCreature::setNextState(InputInfo info) {
    nextState = std::unique_ptr<State>(new MoveStateCreature(info));
}

void MoveStateCreature::resetState() {}

bool MoveStateCreature::isOnPursuit(uint pursuitId) {
    return false;
}

bool MoveStateCreature::isAttacking() {
    return false;
}

bool MoveStateCreature::isMeditating() {
    return false;
}
