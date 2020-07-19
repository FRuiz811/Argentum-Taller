 #include "StillStateCreature.h"

 StillStateCreature::StillStateCreature() {
    finalized = true;
    stateId = StateID::Still;
}

 void StillStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                      Board &board) {}

 StateID StillStateCreature::getNextStateID(InputInfo info) {
     return StateID::Move;
 }

 StateID StillStateCreature::getResetStateID() {
     return StateID::Still;
 }

 bool StillStateCreature::isOnPursuit(uint pursuitId) {
     return false;
 }

 bool StillStateCreature::isAttacking() {
     return false;
 }

 bool StillStateCreature::isMeditating() {
     return false;
 }

 StillStateCreature::~StillStateCreature() = default;
