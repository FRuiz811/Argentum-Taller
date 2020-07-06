#include "MoveStateCreature.h"
#include "StillStateCreature.h"
#include "Creature.h"

MoveStateCreature::~MoveStateCreature() = default;

void MoveStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                    Board &board, GameStatsConfig &gameStatsConfig) {
    std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
    if (amountMovements == 0) {
        amountMovements = 10;
        aCreature->setDirection(direction);
    } else {
        BoardPosition& boardPosition = aCreature->getBoardPosition();
        Point newPoint = aCreature->getBoardPosition().getPosition().getPoint();
        switch(direction) {
            case Direction::up:
                newPoint.y -= distance/float(amountMovements);
                break;
            case Direction::down:
                newPoint.y += distance/float(amountMovements);
                break;
            case Direction::left:
                newPoint.x -= distance/float(amountMovements);
                break;
            case Direction::right:
                newPoint.x += distance/float(amountMovements);
                break;
        }
        Position newPosition(newPoint, boardPosition.getPosition().getWidth(), aCreature->getBoardPosition().getPosition().getHeight());
        if (!board.checkCreaturesCollisions(boardPosition, newPosition, aCreature->getId())) {
            boardPosition.setPosition(newPosition);
        } else {
            isColliding = true;
            finalized = true;
        }
        actualMovement++;
        if (actualMovement >= amountMovements) {
            finalized = true;
        }
    }

}

void MoveStateCreature::setNextState(InputInfo info) {
    if (info.input == InputID::stopMove) {
        nextState = std::unique_ptr<State>(new StillStateCreature());
    } else if (info.input != inputInfo.input) {
        nextState = std::unique_ptr<State>(new MoveStateCreature(info));
    }
}

void MoveStateCreature::resetState() {}

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
