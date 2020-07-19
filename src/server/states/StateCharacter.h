#ifndef ARGENTUM_TALLER_STATECHARACTER_H
#define ARGENTUM_TALLER_STATECHARACTER_H


#include "State.h"

class StateCharacter : public State {
public:
    StateCharacter();

    ~StateCharacter() override;

    virtual bool isMeditating() = 0;
};


#endif //ARGENTUM_TALLER_STATECHARACTER_H
