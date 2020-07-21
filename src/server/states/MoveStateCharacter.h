#ifndef ARGENTUM_TALLER_MOVESTATECHARACTER_H
#define ARGENTUM_TALLER_MOVESTATECHARACTER_H


#include <MovementCharacter.h>
#include "State.h"

class MoveStateCharacter : public State {
private:
    Direction direction;
    MovementCharacter movement;

public:
    explicit MoveStateCharacter(const InputInfo &info);

    ~MoveStateCharacter() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void resetState() override;

    bool isAttacking() override;

    bool isMeditating() override;

    void setNextState(InputInfo info) override;
};


#endif //ARGENTUM_TALLER_MOVESTATECHARACTER_H
