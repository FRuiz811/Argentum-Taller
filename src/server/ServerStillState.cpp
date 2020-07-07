#include "ServerStillState.h"
#include "ServerMoveState.h"


ServerStillState::~ServerStillState() = default;

ServerStillState::ServerStillState(InputInfo anInputInfo) : State(anInputInfo) {
    finalized = true;
    stateId = CharacterStateID::Still;
}

void
ServerStillState::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                              GameStatsConfig &gameStatsConfig) {

}

void ServerStillState::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new ServerMoveState(info));
    }
}

void ServerStillState::resetState() {}

bool ServerStillState::isOnPursuit(uint pursuitId) {
    return false;
}

bool ServerStillState::isAttacking() {
    return false;
}

