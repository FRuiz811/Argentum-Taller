#ifndef MEDITATESTATE_H
#define MEDITATESTATE_H

#include "CharacterState.h"

class MeditateState: public CharacterState {
public:
    MeditateState();
    ~MeditateState();

    virtual InputInfo moveUp(Character& character);
    virtual InputInfo moveDown(Character& character);
    virtual InputInfo moveLeft(Character& character);
    virtual InputInfo moveRight(Character& character);
    virtual InputInfo stopMove(Character& character);

    virtual InputInfo selectItem(Character& character, int item);
    virtual InputInfo dropItem(Character& character, int item);
    
    virtual InputInfo buyItem(Character& character, int item);
    virtual InputInfo sellItem(Character& character, int item);

    virtual InputInfo meditate(Character& character);
    virtual InputInfo resurrect(Character& character);
    virtual InputInfo cure(Character& character);
    virtual InputInfo takeItem(Character& character);
    virtual InputInfo selectTarget(Character& character, Point position);
};

#endif