#ifndef ARGENTUM_TALLER_SERVERSTILLSTATE_H
#define ARGENTUM_TALLER_SERVERSTILLSTATE_H

#include <memory>
#include <vector>
#include <unordered_map>
#include "State.h"
#include "../common/PlayerStats.h"
#include "GameObject.h"
#include "../common/StaticObject.h"

class ServerStillState: public State {
public:
    explicit ServerStillState(InputInfo);

    ~ServerStillState() override;

    bool isOnPursuit(uint pursuitId) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isAttacking() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board, GameStatsConfig &gameStatsConfig) override;

};


#endif //ARGENTUM_TALLER_SERVERSTILLSTATE_H
