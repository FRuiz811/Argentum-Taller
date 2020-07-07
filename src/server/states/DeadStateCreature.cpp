#include "DeadStateCreature.h"

DeadStateCreature::~DeadStateCreature() = default;

DeadStateCreature::DeadStateCreature() {
    stateId = CharacterStateID::Dead;
}

void DeadStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                    Board &board, GameStatsConfig &gameStatsConfig) {

}

void DeadStateCreature::setNextState(InputInfo info) {

}

void DeadStateCreature::resetState() {

}

bool DeadStateCreature::isOnPursuit(uint pursuitId) {
    return false;
}

bool DeadStateCreature::isAttacking() {
    return false;
}
