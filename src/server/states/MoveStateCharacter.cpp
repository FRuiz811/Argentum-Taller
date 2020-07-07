#include <iostream>
#include "MoveStateCharacter.h"
#include "../Collider.h"
#include "../GameCharacter.h"
#include "StillStateCharacter.h"
#include "../Creature.h"
#include "AttackStateCharacter.h"

MoveStateCharacter::~MoveStateCharacter() = default;

MoveStateCharacter::MoveStateCharacter(const InputInfo &info) : State(info) {
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

void MoveStateCharacter::performTask(uint id,
                                     std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                     Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    BoardPosition& boardPosition = aCharacter->getBoardPosition();
    if (!movement.hasStart()) {
        movement.start(boardPosition.getPosition(), direction, gameStatsConfig, aCharacter->getRace());
        aCharacter->setDirection(direction);
    } else {
        Position newPosition = movement.doStep();
        if (!board.checkCollisions(boardPosition, newPosition, aCharacter->getId())) {
            boardPosition.setPosition(newPosition);
            boardPosition.setInsideCity(board.isInsideACity(newPosition));
            uint nestId = board.isInsideANest(newPosition);
            if (nestId != 0 && nestId != boardPosition.getNestId()) {
                std::shared_ptr<Creature> aCreature;
                for(auto &creatureId : board.getCreaturesInNestPoint(nestId)) {
                    aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(creatureId));
                    aCreature->notify(id);
                }
            }
            boardPosition.setNestId(nestId);
        } else {
            isColliding = true;
            finalized = true;
        }
        if (movement.isOver()) {
            finalized =true;
        }
    }

}

void MoveStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if(info.input == InputID::stopMove) {
        nextState = std::unique_ptr<State>(new StillStateCharacter(info));
    } else if (info.input == InputID::selectTarget) {
        this->nextState = std::unique_ptr<State>(new AttackStateCharacter(info));
    }
}

void MoveStateCharacter::resetState() {
    if (isColliding) {
        nextState = std::unique_ptr<State>(new StillStateCharacter(inputInfo));
    } else {
        movement.reset();
        finalized = false;
    }
}

bool MoveStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool MoveStateCharacter::isAttacking() {
    return false;
}
