#include "MeditateStateCharacter.h"

MeditateStateCharacter::~MeditateStateCharacter() = default;

MeditateStateCharacter::MeditateStateCharacter() {
    finalized = true;
    stateId = StateID::Meditate;
}

void MeditateStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                         Board &board) {
}

bool MeditateStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool MeditateStateCharacter::isAttacking() {
    return false;
}

bool MeditateStateCharacter::isMeditating() {
    return true;
}

StateID MeditateStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    }
    return nextStateId;
}

StateID MeditateStateCharacter::getResetStateID() {
    return StateID::Meditate;
}
