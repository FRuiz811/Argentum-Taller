#ifndef ARGENTUM_TALLER_ATTACKSTATECREATURE_H
#define ARGENTUM_TALLER_ATTACKSTATECREATURE_H


#include "StateCreature.h"

class AttackStateCreature : public StateCreature {
private:
    uint enemyId = 0;
    bool enemyIsDead;
    uint8_t timeBetweenAttacks = 0;
    std::shared_ptr<GameObject> aEnemy = nullptr;
public:
    AttackStateCreature();

    ~AttackStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isOnPursuit(uint pursuitId) override;

    void init(InputInfo aInputInfo) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_ATTACKSTATECREATURE_H
