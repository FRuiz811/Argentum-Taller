#ifndef CHARACTERSTATESID_H
#define CHARACTERSTATESID_H

enum class CharacterStateID {
    Still, //Aplica a NPC
    StartMoving, //Aplica a NPC
    Move,  //Aplica a NPC
    Attack, //Aplica a NPC
    Dying, 
    Dead,
    Interact,
};

enum class InputID {
    nothing,
    stopMove,
    up, //w
    down, //s
    left, //a
    right, //d
    resurrect, //r
    buy,       //b
    sell,      //v
    deposit,   //g
    selectTarget, //click
    item1, 
    item2,
    item3,
    item4,
    item5,
    item6,
    item7,
    item8,
    item9,
    dropItem, //f
};

#endif