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
    explicit StatePoolCharacter(GameObject &aCharacter);

    void updateState() override;

    ~StatePoolCharacter() override;

    void performTask(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    bool isPossibleDeadState(StateID id);

    bool isMeditating();

    void changeState(StateID id, InputInfo aInputInfo) override;

    void setNextState(StateID id, InputInfo aInputInfo) override;

    StateID getStateId() override;

    std::shared_ptr<StateCharacter> generateState(StateID id);
};


#endif //ARGENTUM_TALLER_STATEPOOLCHARACTER_H
