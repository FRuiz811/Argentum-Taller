#ifndef STILLSTATE_H
#define STILLSTATE_H

#include "CharacterState.h"

class StillState: public CharacterState {
public:
    StillState();
    ~StillState();

    virtual InputID moveUp(Character& character);
    virtual InputID moveDown(Character& character);
    virtual InputID moveLeft(Character& character);
    virtual InputID moveRight(Character& character);
    virtual InputID stopMove(Character& character);
};

#endif