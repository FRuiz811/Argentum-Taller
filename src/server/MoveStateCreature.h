#ifndef ARGENTUM_TALLER_MOVESTATECREATURE_H
#define ARGENTUM_TALLER_MOVESTATECREATURE_H


#include "State.h"
#include "Movement.h"

class MoveStateCreature : public State {
private:
    Direction direction;
    Movement movement;
public:
    explicit MoveStateCreature(InputInfo info);

    ~MoveStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                     GameStatsConfig &gameStatsConfig) override;

    void setNextState(InputInfo info) override;

    bool isOnPursuit(uint pursuitId) override;

    void resetState() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECREATURE_H
