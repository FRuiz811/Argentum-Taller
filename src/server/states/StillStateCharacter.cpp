#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "AttackStateCharacter.h"
#include "../GameCharacter.h"
#include "EquipStateCharacter.h"
#include "TransitionStateCharacter.h"
#include "../ObjectItem.h"
#include "TakeAndDropStateCharacter.h"
#include "MeditateStateCharacter.h"
#include <iostream>

StillStateCharacter::~StillStateCharacter() = default;

StillStateCharacter::StillStateCharacter(InputInfo anInputInfo) : State(anInputInfo) {
    finalized = true;
    stateId = CharacterStateID::Still;
}

void StillStateCharacter::performTask(uint id,
        std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {}

void StillStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::selectTarget) {
        this->nextState = std::unique_ptr<State>(new TransitionStateCharacter(info));
    } else if (info.input == InputID::equipItem || info.input == InputID::unequipItem) {
        nextState = std::unique_ptr<State>(new EquipStateCharacter(info));
    } else if (info.input == InputID::takeItem || info.input == InputID::dropItem) {
        nextState = std::unique_ptr<State>(new TakeAndDropStateCharacter(info));
    } else if (info.input == InputID::meditate) {
        nextState = std::unique_ptr<State>(new MeditateStateCharacter());
    }
}

void StillStateCharacter::resetState() {}

bool StillStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool StillStateCharacter::isAttacking() {
    return false;
}

StillStateCharacter::StillStateCharacter() {
    finalized = true;
    stateId = CharacterStateID::Still;
}

bool StillStateCharacter::isMeditating() {
    return false;
}


