#ifndef CHARACTERSTATE_H
#define CHARACTERSTATE_H

#include "CharacterStatesID.h"
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

    virtual InputID moveUp(Character& character) = 0;
    virtual InputID moveDown(Character& character) = 0;
    virtual InputID moveLeft(Character& character) = 0;
    virtual InputID moveRight(Character& character) = 0;
    virtual InputID stopMove(Character& character) = 0;
    
   /* virtual InputID selectItem1(Character& character) = 0;
    virtual InputID selectItem2(Character& character) = 0;
    virtual InputID selectItem3(Character& character) = 0;
    virtual InputID selectItem4(Character& character) = 0;
    virtual InputID selectItem5(Character& character) = 0;
    virtual InputID selectItem6(Character& character) = 0;
    virtual InputID selectItem7(Character& character) = 0;
    virtual InputID selectItem8(Character& character) = 0;
    virtual InputID selectItem9(Character& character) = 0;

    virtual InputID dropItem(Character& character) = 0;
    virtual InputID selectTarget(Character& character) = 0;*/

};

#endif