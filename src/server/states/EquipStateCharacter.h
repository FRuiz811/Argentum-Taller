#ifndef ARGENTUM_TALLER_EQUIPSTATECHARACTER_H
#define ARGENTUM_TALLER_EQUIPSTATECHARACTER_H


#include "StateCharacter.h"

class EquipStateCharacter : public StateCharacter {
private:
    int itemToChange{0};
public:
    explicit EquipStateCharacter();

    ~EquipStateCharacter() override;

    void
    performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    bool isMeditating() override;

    void init(InputInfo aInputInfo) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_EQUIPSTATECHARACTER_H
