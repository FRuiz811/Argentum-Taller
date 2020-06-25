#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

#include "../../common/Identificators.h"
#include "../Character.h"

class CharacterState {
private:
    CharacterStateID id;
public:
    CharacterState(CharacterStateID state) : id(state) {}
    virtual ~CharacterState() = default;
    virtual CharacterStateID& getState() {
        return this->id;
    }

    virtual InputInfo moveUp(Character& character) = 0;
    virtual InputInfo moveDown(Character& character) = 0;
    virtual InputInfo moveLeft(Character& character) = 0;
    virtual InputInfo moveRight(Character& character) = 0;
    virtual InputInfo stopMove(Character& character) = 0;

    virtual InputInfo selectItem(Character& character, int item) = 0;

    //virtual InputInfo dropItem(Character& character) = 0;
    virtual InputInfo selectTarget(Character& character, Point position) = 0;

};

#endif