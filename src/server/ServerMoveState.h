#ifndef ARGENTUM_TALLER_SERVERMOVESTATE_H
#define ARGENTUM_TALLER_SERVERMOVESTATE_H


#include "State.h"
#include "Movement.h"

class ServerMoveState : public State {
private:
    Direction direction;
    bool isColliding = false;
    Movement movement;

public:
    explicit ServerMoveState(const InputInfo &info);

    ~ServerMoveState() override;

    bool isOnPursuit(uint pursuitId) override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

    void resetState() override;

    bool isAttacking() override;

    void setNextState(InputInfo info) override;
};


#endif //ARGENTUM_TALLER_SERVERMOVESTATE_H
