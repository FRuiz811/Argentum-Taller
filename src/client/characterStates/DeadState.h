#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "CharacterState.h"

class DeadState: public CharacterState {
public:
    DeadState();
    ~DeadState();

    virtual InputID moveUp(Character& character);
    virtual InputID moveDown(Character& character);
    virtual InputID moveLeft(Character& character);
    virtual InputID moveRight(Character& character);
    virtual InputID stopMove(Character& character);
};

#endif