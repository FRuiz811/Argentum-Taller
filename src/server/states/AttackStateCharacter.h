#ifndef ARGENTUM_TALLER_ATTACKSTATECHARACTER_H
#define ARGENTUM_TALLER_ATTACKSTATECHARACTER_H


#include "State.h"
#include "StateCharacter.h"

class AttackStateCharacter : public StateCharacter {
private:
    uint8_t timeBetweenAttacks = 0;
    bool enemyReceiveDamage = false;
    std::shared_ptr<GameObject> aEnemy = nullptr;
public:
    AttackStateCharacter();

    ~AttackStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    void init(InputInfo aInputInfo) override;

    bool isAttacking() override;

    bool isMeditating() override;
};


#endif //ARGENTUM_TALLER_ATTACKSTATECHARACTER_H
