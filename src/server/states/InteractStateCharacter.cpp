#include "InteractStateCharacter.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"

#include "../GameCharacter.h"

InteractStateCharacter::InteractStateCharacter(const InputInfo &info) : State(info) {
    stateId = CharacterStateID::Interact;
}

InteractStateCharacter::~InteractStateCharacter() = default;

void InteractStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    try {
        uint npcId = board.getIdFromPoint(inputInfo.position);
        if (npcId != 0) {
            std::shared_ptr<GameObject> aNpc = gameObjects.at(npcId);
            if (aNpc->getBoardPosition().getPosition().distance(aCharacter->getBoardPosition().getPosition()) < 30) {
                NPCInfo info = aNpc->interact(*aCharacter,inputInfo);
                aCharacter->setInteractInfo(info);
            }
        } 
        finalized = true;
    } catch (const std::out_of_range& e) {
        finalized = true;
    }
}

void InteractStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::buy || info.input == InputID::cure ||
        info.input == InputID::sell || info.input == InputID::resurrect ||
        info.input == InputID::retire || info.input == InputID::deposit) {
        this->nextState = std::unique_ptr<State>(new InteractStateCharacter(info));
    }
    nextState = std::unique_ptr<State>(new StillStateCharacter(info));
}

void InteractStateCharacter::resetState() {

}

bool InteractStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool InteractStateCharacter::isAttacking() {
    return false;
}
