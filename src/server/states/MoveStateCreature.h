#ifndef ARGENTUM_TALLER_MOVESTATECREATURE_H
#define ARGENTUM_TALLER_MOVESTATECREATURE_H


#include <MovementCreature.h>
#include "State.h"

class MoveStateCreature : public State {
private:
    Direction direction;
    MovementCreature movement;
public:
    explicit MoveStateCreature(InputInfo info);

    ~MoveStateCreature() override;

    void performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void setNextState(InputInfo info) override;

    bool isOnPursuit(uint pursuitId) override;

    void resetState() override;

    bool isMeditating() override;

    bool isAttacking() override;
};


#endif //ARGENTUM_TALLER_MOVESTATECREATURE_H
