#ifndef ARGENTUM_TALLER_DEADSTATECREATURE_H
#define ARGENTUM_TALLER_DEADSTATECREATURE_H


#include "State.h"

class DeadStateCreature : public State {
public:
    DeadStateCreature();

    ~DeadStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;

    bool isOnPursuit(uint pursuitId) override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_DEADSTATECREATURE_H
