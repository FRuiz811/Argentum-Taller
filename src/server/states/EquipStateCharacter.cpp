#include "EquipStateCharacter.h"
#include "../GameCharacter.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "InteractStateCharacter.h"
#include "TransitionStateCharacter.h"

EquipStateCharacter::~EquipStateCharacter() = default;

EquipStateCharacter::EquipStateCharacter(const InputInfo &info) : State(info) {
    finalized = true;

}

void EquipStateCharacter::performTask(uint id,
        std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (inputInfo.aditional != 0) {
        aCharacter->equipItem(inputInfo.aditional);
    }
}

void EquipStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if(info.input == InputID::stopMove) {
        nextState = std::unique_ptr<State>(new StillStateCharacter(info));
    } else if (info.input == InputID::selectTarget) {
        nextState = std::unique_ptr<State>(new TransitionStateCharacter(info));
    } else if (info.input == InputID::equipItem) {
        nextState = std::unique_ptr<State>(new EquipStateCharacter(info));
    }
}

void EquipStateCharacter::resetState() {
    nextState = std::unique_ptr<State>(new StillStateCharacter());
}

bool EquipStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool EquipStateCharacter::isAttacking() {
    return false;
}
