#ifndef ARGENTUM_TALLER_TRANSITIONSTATECHARACTER_H
#define ARGENTUM_TALLER_TRANSITIONSTATECHARACTER_H


#include "State.h"

class TransitionStateCharacter : public State {
private:
    bool isAnAttack = true;
public:
    TransitionStateCharacter(InputInfo info);

    ~TransitionStateCharacter() override;

    void
    performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_TRANSITIONSTATECHARACTER_H
