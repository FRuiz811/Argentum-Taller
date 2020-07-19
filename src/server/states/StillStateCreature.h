#ifndef ARGENTUM_TALLER_STILLSTATECREATURE_H
#define ARGENTUM_TALLER_STILLSTATECREATURE_H

#include "State.h"
#include "StateCreature.h"

class StillStateCreature : public StateCreature {
private:
public:
    StillStateCreature();

    ~StillStateCreature() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    bool isAttacking() override;

    StateID getResetStateID() override;

    void init(InputInfo aInputInfo) override;
};


#endif //ARGENTUM_TALLER_STILLSTATECREATURE_H
