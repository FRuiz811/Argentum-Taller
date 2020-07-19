#ifndef ARGENTUM_TALLER_MOVESTATECHARACTER_H
#define ARGENTUM_TALLER_MOVESTATECHARACTER_H


#include "State.h"
#include "../Movement.h"

class MoveStateCharacter : public State {
private:
    Direction direction;
    Movement movement;
public:
    explicit MoveStateCharacter(const InputInfo &info);

    ~MoveStateCharacter() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    bool isAttacking() override;

    bool isMeditating() override;

    StateID getNextStateID(InputInfo info) override;

    StateID getResetStateID() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECHARACTER_H
