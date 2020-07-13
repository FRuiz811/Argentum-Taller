#ifndef ARGENTUM_TALLER_ATTACKSTATECHARACTER_H
#define ARGENTUM_TALLER_ATTACKSTATECHARACTER_H


#include "State.h"

class AttackStateCharacter : public State {
private:
    uint8_t timeBetweenAttacks = 0;
    bool enemyReceiveDamage = false;
    std::shared_ptr<GameObject> aEnemy = nullptr;
public:
    AttackStateCharacter(InputInfo info);

    ~AttackStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;

    bool isMeditating() override;
};


#endif //ARGENTUM_TALLER_ATTACKSTATECHARACTER_H
