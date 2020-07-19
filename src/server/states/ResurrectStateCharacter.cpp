#include "ResurrectStateCharacter.h"

ResurrectStateCharacter::~ResurrectStateCharacter() {

}

void ResurrectStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

}

StateID ResurrectStateCharacter::getNextStateID(InputInfo info) {
    return StateID::Pursuit;
}

StateID ResurrectStateCharacter::getResetStateID() {
    return StateID::Resurrect;
}

bool ResurrectStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool ResurrectStateCharacter::isAttacking() {
    return false;
}

bool ResurrectStateCharacter::isMeditating() {
    return false;
}
