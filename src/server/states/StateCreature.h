#ifndef ARGENTUM_TALLER_STATECREATURE_H
#define ARGENTUM_TALLER_STATECREATURE_H


#include "State.h"

class StateCreature : public State {
public:
    ~StateCreature() override;

    StateID getResetStateID() override;

    virtual bool isOnPursuit(uint pursuitId) = 0;
};


#endif //ARGENTUM_TALLER_STATECREATURE_H
