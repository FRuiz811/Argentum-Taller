#ifndef ARGENTUM_TALLER_SERVERMOVESTATE_H
#define ARGENTUM_TALLER_SERVERMOVESTATE_H


#include "State.h"

class ServerMoveState : public State {
private:
    Direction direction;
    uint amountMovements = 0;
    uint actualMovement = 0;
    float distance = 15.0;
public:
    explicit ServerMoveState(const InputInfo &info);

    ~ServerMoveState() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

    void resetState() override;

    void setNextState(InputInfo info) override;
};


#endif //ARGENTUM_TALLER_SERVERMOVESTATE_H
