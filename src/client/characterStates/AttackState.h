#ifndef ATTACKSTATE_H
#define ATTACKSTATE_H

#include "CharacterState.h"

class AttackState: public CharacterState {
public:
    AttackState();
    ~AttackState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);

    virtual InputInfo selectItem(Character& character, int item);
    virtual InputInfo meditate(Character& character);
    virtual InputInfo resurrect(Character& character);
    virtual InputInfo cure(Character& character);
    virtual InputInfo takeItem(Character& character);
    virtual InputInfo selectTarget(Character& character, Point position);
};

#endif