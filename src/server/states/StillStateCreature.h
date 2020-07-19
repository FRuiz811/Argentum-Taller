#ifndef ARGENTUM_TALLER_STILLSTATECREATURE_H
#define ARGENTUM_TALLER_STILLSTATECREATURE_H

#include "State.h"

class StillStateCreature : public State {
private:
public:
    StillStateCreature();

    virtual ~StillStateCreature();

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isAttacking() override;

    bool isMeditating() override;

};


#endif //ARGENTUM_TALLER_STILLSTATECREATURE_H
