#ifndef ARGENTUM_TALLER_ATTACKSTATECREATURE_H
#define ARGENTUM_TALLER_ATTACKSTATECREATURE_H


#include "State.h"

class AttackStateCreature : public State {
private:
    uint enemyId;
    bool enemyIsDead;
    uint8_t timeBetweenAttacks = 0;
    std::shared_ptr<GameObject> aEnemy = nullptr;
public:
    AttackStateCreature(uint enemyId);

    ~AttackStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isMeditating() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_ATTACKSTATECREATURE_H
