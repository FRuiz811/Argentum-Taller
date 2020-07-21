#ifndef ARGENTUM_TALLER_PURSUITSTATECREATURE_H
#define ARGENTUM_TALLER_PURSUITSTATECREATURE_H


#include <MovementCreature.h>
#include "State.h"
#include "../Creature.h"
#include "StateCreature.h"

class PursuitStateCreature : public StateCreature {
private:
    uint pursuitId;
    MovementCreature movement;
    bool canAttack = false;

public:
    explicit PursuitStateCreature();

    ~PursuitStateCreature() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    void init(InputInfo aInputInfo) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_PURSUITSTATECREATURE_H
