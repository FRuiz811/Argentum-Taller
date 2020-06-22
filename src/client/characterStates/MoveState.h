#ifndef MOVESTATE_H
#define MOVESTATE_H

#include "CharacterState.h"

class MoveState: public CharacterState {
public:
    MoveState();
    ~MoveState();

    virtual InputID moveUp(Character& character);
    virtual InputID moveDown(Character& character);
    virtual InputID moveLeft(Character& character);
    virtual InputID moveRight(Character& character);
    virtual InputID stopMove(Character& character);
};

#endif