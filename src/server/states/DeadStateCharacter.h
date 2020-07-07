#ifndef ARGENTUM_TALLER_DEADSTATECHARACTER_H
#define ARGENTUM_TALLER_DEADSTATECHARACTER_H


#include "State.h"
#include "../Movement.h"

class DeadStateCharacter : public State {
private:
    Movement movement;
    Direction direction;
    bool canTakeAnotherAction = true;
public:
    DeadStateCharacter();

    ~DeadStateCharacter() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_DEADSTATECHARACTER_H
