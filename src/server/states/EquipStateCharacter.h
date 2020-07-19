#ifndef ARGENTUM_TALLER_EQUIPSTATECHARACTER_H
#define ARGENTUM_TALLER_EQUIPSTATECHARACTER_H


#include "State.h"

class EquipStateCharacter : public State {
private:
    int itemToChange{0};
public:
    EquipStateCharacter(const InputInfo &info);

    ~EquipStateCharacter() override;

    void
    performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isMeditating() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_EQUIPSTATECHARACTER_H
