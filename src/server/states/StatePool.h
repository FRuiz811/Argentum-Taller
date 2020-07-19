#ifndef ARGENTUM_TALLER_STATEPOOL_H
#define ARGENTUM_TALLER_STATEPOOL_H

#include "State.h"

class StatePool {
public:
    StatePool();

    virtual void changeState(StateID id, InputInfo aInputInfo) = 0;

    virtual void setNextState(StateID id, InputInfo aInputInfo) = 0;

    virtual void updateState(InputInfo aInputInfo) = 0;

    virtual ~StatePool();
};

#endif //ARGENTUM_TALLER_STATEPOOL_H
