#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "AttackStateCharacter.h"
#include "InteractStateCharacter.h"
#include "../GameCharacter.h"
#include <iostream>

StillStateCharacter::~StillStateCharacter() = default;

StillStateCharacter::StillStateCharacter(InputInfo anInputInfo) : State(anInputInfo) {
    finalized = true;
    stateId = CharacterStateID::Still;
}

void
StillStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                                 GameStatsConfig &gameStatsConfig) {
    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (this->itemToChange != 0) {
        aCharacter->equipItem(itemToChange);
        this->itemToChange = 0;
    }
}

void StillStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::selectTarget) {
        //this->nextState = std::unique_ptr<State>(new AttackStateCharacter(info));
        this->nextState = std::unique_ptr<State>(new InteractStateCharacter(info));
    } else if (info.input == InputID::equipItem) {
        this->itemToChange = info.aditional;
    }
}

void StillStateCharacter::resetState() {}

bool StillStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool StillStateCharacter::isAttacking() {
    return false;
}


