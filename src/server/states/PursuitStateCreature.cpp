#include "PursuitStateCreature.h"
#include "StillStateCreature.h"
#include "../GameCharacter.h"
#include "AttackStateCreature.h"

PursuitStateCreature::~PursuitStateCreature() = default;

PursuitStateCreature::PursuitStateCreature(uint id) : pursuitId(id) {
    stateId = CharacterStateID::Move;
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

void PursuitStateCreature::setNextState(InputInfo info) {
    if (canAttack) {
        nextState = std::unique_ptr<State>(new AttackStateCreature(pursuitId));
    } else {
        nextState = std::unique_ptr<State>(new StillStateCreature());
    }
}

void PursuitStateCreature::resetState() {}

bool PursuitStateCreature::isOnPursuit(uint aPursuitId) {
    return pursuitId == aPursuitId;
}

bool PursuitStateCreature::isAttacking() {
    return false;
}
