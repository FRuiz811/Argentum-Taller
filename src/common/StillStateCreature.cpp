 #include "StillStateCreature.h"
#include "MoveStateCreature.h"

 StillStateCreature::StillStateCreature() {
    finalized = true;
    stateId = CharacterStateID::Still;
}

 void StillStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                      Board &board, GameStatsConfig &gameStatsConfig) {}

 void StillStateCreature::setNextState(InputInfo info) {
    if (info.input != InputID::stopMove) {
        nextState = std::unique_ptr<State>(new MoveStateCreature(inputInfo));
    }
 }

 void StillStateCreature::resetState() {}

 StillStateCreature::~StillStateCreature() = default;
