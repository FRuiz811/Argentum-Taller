#ifndef ARGENTUM_TALLER_RESURRECTSTATECHARACTER_H
#define ARGENTUM_TALLER_RESURRECTSTATECHARACTER_H

#include <Movement.h>
#include "StateCharacter.h"

class ResurrectStateCharacter : public StateCharacter {
private:
    std::shared_ptr<Cell> aPriestCell = nullptr;
    Movement movement;
public:
    ResurrectStateCharacter();

    ~ResurrectStateCharacter() override;

    void
    performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;

    void init(InputInfo aInputInfo) override;

    bool isAttacking() override;

    bool isMeditating() override;
};


#endif //ARGENTUM_TALLER_RESURRECTSTATECHARACTER_H
