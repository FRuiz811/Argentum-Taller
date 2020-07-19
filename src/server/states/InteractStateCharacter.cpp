#include "InteractStateCharacter.h"
#include "../GameCharacter.h"

InteractStateCharacter::InteractStateCharacter() : StateCharacter() {
    stateId = StateID::Interact;
}

InteractStateCharacter::~InteractStateCharacter() = default;

void InteractStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    std::shared_ptr<Cell> npcCell = board.getCellFromPoint(inputInfo.position);
    if (!interacting) {
        if (npcCell->getGameObjectId() != 0 && npcCell != aCharacter->getActualCell()) {
            aNpc = gameObjects.at(npcCell->getGameObjectId());
            if (board.getDistance(npcCell, aCharacter->getActualCell()) == 1) {
                NPCInfo info = aNpc->interact(*aCharacter,inputInfo);
                if (info.type != 0) {
                    aCharacter->setInteractInfo(info);
                    interacting = true;
                } else {
                    finalized = true;
                }
            }
        } else {
            finalized = true;
        }
    } else {
        if (aCharacter->hasAnInputInfo()) {
            InputInfo info = aCharacter->getNextInputInfo();
            if (aCharacter->isDead() && !(info.input == InputID::resurrect)) {
                finalized = true;
                return;
            }
            if (info.input == InputID::buy || info.input == InputID::cure ||
                info.input == InputID::sell || info.input == InputID::resurrect ||
                info.input == InputID::retireItem || info.input == InputID::retireGold ||
                info.input == InputID::depositItem || info.input == InputID::depositGold) {
                try {
                    aCharacter->setInteractInfo(aNpc->interact(*aCharacter, info));
                } catch (Exception &e) {
                    finalized = true;
                }
            } else {
                finalized = true;
            }
        }
    }
}

StateID InteractStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    }
    return nextStateId;
}

StateID InteractStateCharacter::getResetStateID() {
    return StateID::Still;
}

bool InteractStateCharacter::isAttacking() {
    return false;
}

bool InteractStateCharacter::isMeditating() {
    return false;
}

void InteractStateCharacter::init(InputInfo aInputInfo) {
    interacting = false;
    aNpc = nullptr;
    inputInfo = aInputInfo;
}


