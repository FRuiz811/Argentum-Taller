#ifndef MOVESTATE_H
#define MOVESTATE_H

#include "CharacterState.h"

class MoveState: public CharacterState {
public:
    MoveState();
    ~MoveState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);
};

#endif