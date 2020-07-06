#include "PursuitStateCreature.h"

PursuitStateCreature::~PursuitStateCreature() = default;

void PursuitStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board, GameStatsConfig &gameStatsConfig) {

}

void PursuitStateCreature::setNextState(InputInfo info) {

}

void PursuitStateCreature::resetState() {

}

PursuitStateCreature::PursuitStateCreature(uint id) : pursuitId(id) {}
