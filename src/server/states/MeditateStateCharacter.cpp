#include "MeditateStateCharacter.h"
#include "MoveStateCharacter.h"
#include "StillStateCharacter.h"
#include "../GameCharacter.h"
MeditateStateCharacter::~MeditateStateCharacter() = default;

MeditateStateCharacter::MeditateStateCharacter() {
    finalized = true;
    stateId = CharacterStateID::Meditate;
}

void MeditateStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                         Board &board, GameStatsConfig &gameStatsConfig) {
    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (this->itemToChange != 0) {
        aCharacter->equipItem(itemToChange);
        this->itemToChange = 0;
    }
}

void MeditateStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::equipItem)  {
        this->itemToChange = info.aditional;
        this->nextState = std::unique_ptr<State>(new StillStateCharacter(info));
    }
    this->finalized = true;
}

void MeditateStateCharacter::resetState() {

}

bool MeditateStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool MeditateStateCharacter::isAttacking() {
    return false;
}
