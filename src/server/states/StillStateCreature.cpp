 #include "StillStateCreature.h"

 StillStateCreature::StillStateCreature() : StateCreature() {
    finalized = true;
    stateId = StateID::Still;
}

 void StillStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                      Board &board) {}

 StateID StillStateCreature::getNextStateID(InputInfo info) {
     return StateID::Move;
 }

 bool StillStateCreature::isOnPursuit(uint pursuitId) {
     return false;
 }

 bool StillStateCreature::isAttacking() {
     return false;
 }

 void StillStateCreature::init(InputInfo aInputInfo) {
    inputInfo = aInputInfo;
 }

 StateID StillStateCreature::getResetStateID() {
     return StateCreature::getResetStateID();
 }

 StillStateCreature::~StillStateCreature() = default;
