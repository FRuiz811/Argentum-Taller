#ifndef ARGENTUM_TALLER_MOVESTATECHARACTER_H
#define ARGENTUM_TALLER_MOVESTATECHARACTER_H


#include "../Movement.h"
#include "StateCharacter.h"

class MoveStateCharacter : public StateCharacter {
private:
    Direction direction;
    Movement movement;
public:
    MoveStateCharacter();

    ~MoveStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    bool isAttacking() override;

    bool isMeditating() override;

    void init(InputInfo aInputInfo) override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECHARACTER_H
