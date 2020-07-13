#include "TransitionStateCharacter.h"
#include "../GameCharacter.h"
#include "AttackStateCharacter.h"
#include "InteractStateCharacter.h"

TransitionStateCharacter::~TransitionStateCharacter() = default;

TransitionStateCharacter::TransitionStateCharacter(InputInfo info) : State(info) {
    finalized = true;
}

void TransitionStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (aCharacter->getActualCell()->isCity()) {
        nextState = std::unique_ptr<State>(new InteractStateCharacter(inputInfo));
    } else {
        nextState = std::unique_ptr<State>(new AttackStateCharacter(inputInfo));
    }
}

void TransitionStateCharacter::setNextState(InputInfo info) {}

void TransitionStateCharacter::resetState() {}

bool TransitionStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool TransitionStateCharacter::isAttacking() {
    return false;
}

bool TransitionStateCharacter::isMeditating() {
    return false;
}
