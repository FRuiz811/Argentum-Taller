#include "ResurrectStateCharacter.h"

ResurrectStateCharacter::~ResurrectStateCharacter() = default;

void ResurrectStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

}

StateID ResurrectStateCharacter::getNextStateID(InputInfo info) {
    return StateID::Pursuit;
}

StateID ResurrectStateCharacter::getResetStateID() {
    return StateID::Resurrect;
}

bool ResurrectStateCharacter::isAttacking() {
    return false;
}

bool ResurrectStateCharacter::isMeditating() {
    return false;
}

void ResurrectStateCharacter::init(InputInfo aInputInfo) {

}
