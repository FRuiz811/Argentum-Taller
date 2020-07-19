#ifndef ARGENTUM_TALLER_STATEPOOL_H
#define ARGENTUM_TALLER_STATEPOOL_H

#include <GameObject.h>
#include "State.h"

class StatePool {
public:
    StatePool();

    virtual void changeState(StateID id, InputInfo aInputInfo) = 0;

    virtual void setNextState(StateID id, InputInfo aInputInfo) = 0;

    virtual void updateState() = 0;

    virtual void performTask(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
            Board &board) = 0;

    virtual StateID getStateId() = 0;

    virtual ~StatePool();
};

#endif //ARGENTUM_TALLER_STATEPOOL_H
