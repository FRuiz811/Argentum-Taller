#include "StillStateCharacter.h"
#include "AttackStateCharacter.h"
#include <iostream>

StillStateCharacter::~StillStateCharacter() = default;

StillStateCharacter::StillStateCharacter(InputInfo anInputInfo) : State(anInputInfo) {
    finalized = true;
    stateId = StateID::Still;
}

StillStateCharacter::StillStateCharacter() {
    finalized = true;
    stateId = StateID::Still;
}

void StillStateCharacter::performTask(uint id,
        std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {}

StateID StillStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    } else if (info.input == InputID::selectTarget) {
        nextStateId = StateID::Transition;
    } else if (info.input == InputID::equipItem || info.input == InputID::unequipItem) {
        nextStateId = StateID::Equip;
    } else if (info.input == InputID::takeItem || info.input == InputID::dropItem) {
        nextStateId = StateID::TakeDrop;
    } else if (info.input == InputID::meditate) {
        nextStateId = StateID::Meditate;
    }
    return nextStateId;
}

StateID StillStateCharacter::getResetStateID() {
    return StateID::Still;
}

bool StillStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool StillStateCharacter::isAttacking() {
    return false;
}

bool StillStateCharacter::isMeditating() {
    return false;
}

