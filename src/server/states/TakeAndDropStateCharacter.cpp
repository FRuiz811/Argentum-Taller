#include "TakeAndDropStateCharacter.h"
#include "../GameCharacter.h"
#include "../ObjectItem.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"

TakeAndDropStateCharacter::~TakeAndDropStateCharacter() {
    stateId = CharacterStateID::Still;
}

TakeAndDropStateCharacter::TakeAndDropStateCharacter(const InputInfo &info) : State(info) {}

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
    }
    finalized = true;
}


void TakeAndDropStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else {
        nextState = std::unique_ptr<State>(new StillStateCharacter());
    }

}

void TakeAndDropStateCharacter::resetState() {
    nextState = std::unique_ptr<State>(new StillStateCharacter());
}

bool TakeAndDropStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool TakeAndDropStateCharacter::isAttacking() {
    return false;
}

bool TakeAndDropStateCharacter::isMeditating() {
    return false;
}
