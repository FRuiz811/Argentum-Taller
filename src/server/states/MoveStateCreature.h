#ifndef ARGENTUM_TALLER_MOVESTATECREATURE_H
#define ARGENTUM_TALLER_MOVESTATECREATURE_H


#include "../Movement.h"
#include "StateCreature.h"

class MoveStateCreature : public StateCreature {
private:
    Direction direction;
    Movement movement;
public:
    MoveStateCreature();
    ~MoveStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    bool isOnPursuit(uint pursuitId) override;

    void init(InputInfo aInputInfo) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECREATURE_H
