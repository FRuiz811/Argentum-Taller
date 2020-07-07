 #include "StillStateCreature.h"
#include "MoveStateCreature.h"
#include "DeadStateCharacter.h"

 StillStateCreature::StillStateCreature() {
    finalized = true;
    stateId = CharacterStateID::Still;
}

 void StillStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                      Board &board, GameStatsConfig &gameStatsConfig) {}

 void StillStateCreature::setNextState(InputInfo info) {
    nextState = std::unique_ptr<State>(new MoveStateCreature(inputInfo));
 }

 void StillStateCreature::resetState() {}

 bool StillStateCreature::isOnPursuit(uint pursuitId) {
     return false;
 }

 bool StillStateCreature::isAttacking() {
     return false;
 }

 StillStateCreature::~StillStateCreature() = default;
