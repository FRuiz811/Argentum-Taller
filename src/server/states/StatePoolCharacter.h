#ifndef ARGENTUM_TALLER_STATEPOOLCHARACTER_H
#define ARGENTUM_TALLER_STATEPOOLCHARACTER_H

#include "StatePool.h"

class StatePoolCharacter : public StatePool {
private:
    GameObject& character;
public:
    explicit StatePoolCharacter(GameObject &gameObject);

    void updateState(InputInfo aInputInfo) override;

    ~StatePoolCharacter() override;

    void setNextState(StateID id, InputInfo aInputInfo);

    bool isPossibleDeadState(StateID id);

    void changeState(StateID id, InputInfo aInputInfo);

    std::shared_ptr<State> generateState(StateID id, InputInfo aInputInfo);
};


#endif //ARGENTUM_TALLER_STATEPOOLCHARACTER_H
