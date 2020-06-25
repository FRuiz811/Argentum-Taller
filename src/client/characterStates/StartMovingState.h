#ifndef STARTMOVINGSTATE_H
#define STARTMOVINGSTATE_H

#include "CharacterState.h"

class StartMovingState: public CharacterState {
public:
    StartMovingState();
    ~StartMovingState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);

    virtual InputInfo selectItem(Character& character, int item);

    virtual InputInfo selectTarget(Character& character, Point position);
};

#endif