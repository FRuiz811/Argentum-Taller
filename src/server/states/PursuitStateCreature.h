#ifndef ARGENTUM_TALLER_PURSUITSTATECREATURE_H
#define ARGENTUM_TALLER_PURSUITSTATECREATURE_H


#include "State.h"
#include "../Movement.h"
#include "../Creature.h"

class PursuitStateCreature : public State {
private:
    uint pursuitId;
    Movement movement;
    bool canAttack = false;

public:
    explicit PursuitStateCreature(uint id);

    ~PursuitStateCreature() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    bool isMeditating() override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_PURSUITSTATECREATURE_H
