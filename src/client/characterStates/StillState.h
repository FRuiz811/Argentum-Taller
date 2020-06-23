#ifndef STILLSTATE_H
#define STILLSTATE_H

#include "CharacterState.h"

class StillState: public CharacterState {
public:
    StillState();
    ~StillState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);
};

#endif