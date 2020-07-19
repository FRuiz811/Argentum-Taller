#include "TakeAndDropStateCharacter.h"
#include "../GameCharacter.h"
#include "../ObjectItem.h"

TakeAndDropStateCharacter::~TakeAndDropStateCharacter() {
    stateId = StateID::TakeDrop;
}

TakeAndDropStateCharacter::TakeAndDropStateCharacter() : StateCharacter() {}

void TakeAndDropStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                            Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    std::shared_ptr<Cell> characterCell = aCharacter->getActualCell();
    switch (inputInfo.input) {
        case InputID::dropItem:
            if (!characterCell->hasItem()) {
                aCharacter->dropItem(inputInfo.aditional - 1);
            }
            break;
        case InputID::takeItem:
            if (characterCell->hasItem()) {
                std::shared_ptr<ObjectItem> anItem = std::dynamic_pointer_cast<ObjectItem>(gameObjects.at(characterCell->getItemId()));
                if(aCharacter->takeItem(anItem->getItemId(), anItem->getAmount())) {
                    anItem->take();
                }
            }
            break;
        default:
            break;
    }
    finalized = true;
}

StateID TakeAndDropStateCharacter::getNextStateID(InputInfo info) {
    StateID nextState = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextState = StateID::Move;
    }
    return nextState;
}

StateID TakeAndDropStateCharacter::getResetStateID() {
    return StateID::Still;
}

bool TakeAndDropStateCharacter::isAttacking() {
    return false;
}

bool TakeAndDropStateCharacter::isMeditating() {
    return false;
}

void TakeAndDropStateCharacter::init(InputInfo aInputInfo) {
    inputInfo = aInputInfo;
}
