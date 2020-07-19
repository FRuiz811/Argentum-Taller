#ifndef ARGENTUM_TALLER_STATEPOOLCHARACTER_H
#define ARGENTUM_TALLER_STATEPOOLCHARACTER_H

#include "StatePool.h"
#include "StateCharacter.h"

class StatePoolCharacter : public StatePool {
private:
    GameObject& character;
    std::shared_ptr<StateCharacter> actualState;
    std::unordered_map<StateID, std::shared_ptr<StateCharacter>, std::hash<StateID>> states;
public:
    explicit StatePoolCharacter(GameObject &gameObject);

    void updateState(InputInfo aInputInfo) override;

    ~StatePoolCharacter() override;

    bool isPossibleDeadState(StateID id);

    void changeState(StateID id, InputInfo aInputInfo) override;

    void setNextState(StateID id, InputInfo aInputInfo) override;

    std::shared_ptr<StateCharacter> generateState(StateID id);
};


#endif //ARGENTUM_TALLER_STATEPOOLCHARACTER_H
