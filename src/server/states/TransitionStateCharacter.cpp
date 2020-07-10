#include "TransitionStateCharacter.h"

TransitionStateCharacter::~TransitionStateCharacter() = default;

TransitionStateCharacter::TransitionStateCharacter(const InputInfo &info) : State(info) {}

void TransitionStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {



}

void TransitionStateCharacter::setNextState(InputInfo info) {

}

void TransitionStateCharacter::resetState() {

}

bool TransitionStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool TransitionStateCharacter::isAttacking() {
    return false;
}
