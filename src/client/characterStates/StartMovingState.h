#ifndef STARTMOVINGSTATE_H
#define STARTMOVINGSTATE_H

#include "CharacterState.h"

class StartMovingState: public CharacterState {
public:
    StartMovingState();
    ~StartMovingState();

    virtual InputID moveUp(Character& character);
    virtual InputID moveDown(Character& character);
    virtual InputID moveLeft(Character& character);
    virtual InputID moveRight(Character& character);
    virtual InputID stopMove(Character& character);
};

#endif