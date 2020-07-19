#include "EquipStateCharacter.h"
#include "../GameCharacter.h"

EquipStateCharacter::~EquipStateCharacter() = default;

EquipStateCharacter::EquipStateCharacter(const InputInfo &info) : State(info) {
    finalized = true;
    stateId = StateID::Still;
}

void EquipStateCharacter::performTask(uint id,
        std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (inputInfo.input == InputID::unequipItem) {
        aCharacter->unequipItem(inputInfo.aditional);
    } else {
        if (inputInfo.aditional != 0) {
            aCharacter->equipItem(inputInfo.aditional);
        }
    }
}

bool EquipStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool EquipStateCharacter::isAttacking() {
    return false;
}

bool EquipStateCharacter::isMeditating() {
    return false;
}

StateID EquipStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    }
    return nextStateId;
}

StateID EquipStateCharacter::getResetStateID() {
    return StateID::Still;
}
