#include "MeditateStateCharacter.h"
#include "MoveStateCharacter.h"
#include "StillStateCharacter.h"
#include "../GameCharacter.h"
#include "EquipStateCharacter.h"
#include "TransitionStateCharacter.h"

MeditateStateCharacter::~MeditateStateCharacter() = default;

MeditateStateCharacter::MeditateStateCharacter() {
    finalized = true;
    stateId = CharacterStateID::Meditate;
}

void MeditateStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                         Board &board) {
}

void MeditateStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::selectTarget) {
        this->nextState = std::unique_ptr<State>(new TransitionStateCharacter(info));
    } else if (info.input == InputID::equipItem)  {
        this->nextState = std::unique_ptr<State>(new EquipStateCharacter(info));
    } else if (info.input == InputID::meditate) {
        this->nextState = std::unique_ptr<State>(new StillStateCharacter(info));
    }
}

void MeditateStateCharacter::resetState() {}

bool MeditateStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool MeditateStateCharacter::isAttacking() {
    return false;
}

bool MeditateStateCharacter::isMeditating() {
    return true;
}
