#include "MoveStateCreature.h"
#include "StillStateCreature.h"
#include "Creature.h"

MoveStateCreature::~MoveStateCreature() = default;

MoveStateCreature::MoveStateCreature(InputInfo info) : State(info){
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
    stateId = CharacterStateID::Move;
}

void MoveStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                    Board &board, GameStatsConfig &gameStatsConfig) {
    std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
    BoardPosition& boardPosition = aCreature->getBoardPosition();
    if (!movement.hasStart()) {
        movement.start(boardPosition.getPosition(), direction, gameStatsConfig, aCreature->getCreatureId());
        aCreature->setDirection(direction);
    } else {
        Position newPosition = movement.doStep();
        if (!board.checkCreaturesCollisions(boardPosition, newPosition, aCreature->getId())) {
            boardPosition.setPosition(newPosition);
        } else {
            finalized = true;
        }
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
