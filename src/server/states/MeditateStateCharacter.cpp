#include "MeditateStateCharacter.h"
#include "MoveStateCharacter.h"

MeditateStateCharacter::~MeditateStateCharacter() = default;

MeditateStateCharacter::MeditateStateCharacter() {
    finalized = true;
    stateId = CharacterStateID::Meditate;
}

void MeditateStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                         Board &board, GameStatsConfig &gameStatsConfig) {

}

void MeditateStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    }
}

void MeditateStateCharacter::resetState() {

}

bool MeditateStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool MeditateStateCharacter::isAttacking() {
    return false;
}
