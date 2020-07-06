#ifndef ARGENTUM_TALLER_MOVESTATECREATURE_H
#define ARGENTUM_TALLER_MOVESTATECREATURE_H


#include "State.h"

class MoveStateCreature : public State {
private:
    Direction direction;
    uint8_t amountMovements = 0;
    uint8_t actualMovement = 0;
    bool isColliding = false;
    float distance = 10.0;
public:
    MoveStateCreature(InputInfo info);

    ~MoveStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    void resetState() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECREATURE_H
