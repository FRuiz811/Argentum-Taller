#include "PursuitStateCreature.h"
#include "StillStateCreature.h"
#include "../GameCharacter.h"

PursuitStateCreature::~PursuitStateCreature() = default;

PursuitStateCreature::PursuitStateCreature() : StateCreature(), pursuitId(0) {
    stateId = StateID::Pursuit;
    finalized = false;
}

void PursuitStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
    try {
        std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(pursuitId));
        std::shared_ptr<Cell> creatureCell = aCreature->getActualCell();
        std::shared_ptr<Cell> enemyCell = aCharacter->getActualCell();
        if (!movement.hasStart()) {
            if (enemyCell->getNestId() == creatureCell->getNestId()) {
                if (board.getDistance(creatureCell, enemyCell) == 1) {
                    canAttack = true;
                    finalized = true;
                    aCreature->setDirection(board.getDirection(creatureCell, enemyCell));
                } else {
                    std::shared_ptr<Cell> newCell;
                    newCell = board.getBestCell(creatureCell, enemyCell);
                    if (newCell != aCreature->getActualCell()) {
                        Direction aDirection = board.getDirection(creatureCell, newCell);
                        aCreature->setDirection(aDirection);
                        movement.start(board.getPointFromCell(aCreature->getActualCell()), aDirection, aCreature->getCreatureId());
                        aCreature->getActualCell()->free();
                        newCell->occupied(id);
                        aCreature->setCell(newCell);
                    }
                }
            } else {
                finalized = true;
            }
        } else {
            aCreature->setPoint(movement.doStep());
            if (movement.isOver()) {
                movement.reset();
            }
        }
    } catch (const std::out_of_range& e) {
        canAttack = false;
        finalized = true;
    }

}

bool PursuitStateCreature::isOnPursuit(uint aPursuitId) {
    return pursuitId == aPursuitId;
}

bool PursuitStateCreature::isAttacking() {
    return false;
}

StateID PursuitStateCreature::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (canAttack) {
        nextStateId = StateID::Attack;
    }
    return nextStateId;
}

StateID PursuitStateCreature::getResetStateID() {
    return StateID::Pursuit;
}

void PursuitStateCreature::init(InputInfo aInputInfo) {
    inputInfo = aInputInfo;
    pursuitId = aInputInfo.aditional;
    movement.reset();
    canAttack = false;
    finalized = false;
}
