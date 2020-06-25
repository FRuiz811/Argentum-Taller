#ifndef DEADSTATE_H
#define DEADSTATE_H

#include "CharacterState.h"

class DeadState: public CharacterState {
public:
    DeadState();
    ~DeadState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);

    virtual InputInfo selectItem(Character& character, int item);

    virtual InputInfo selectTarget(Character& character, Point position);
};

#endif