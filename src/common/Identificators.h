#ifndef CHARACTERSTATESID_H
#define CHARACTERSTATESID_H

#include "Point.h"

enum class CharacterStateID {
    Still, //Aplica a NPCServer
    StartMoving, //Aplica a NPCServer
    Move,  //Aplica a NPCServer
    Attack, //Aplica a NPCServer
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

struct InputInfo {
    InputID input;
    Point position;
};


enum class HelmetID {
    Nothing,
    Hood,
    IronHelmet,
    MagicHat,
};

enum class BodyID {
    Nothing,
    RedCommon,
    BlueCommon,
    GreenCommon,
    BlueTunic,
    LeatherArmor,
    PlateArmor,
    Ghost,
    Banker,
    Goblin,
    Merchant,
    Priest,
    Skeleton,
    Spider,
    Zombie,
};

enum class HeadID {
    Nothing,
    Elf,
    Human,
    Gnome,
    Dwarf,
    Priest,
    Zombie,
};

enum class ShieldID {
    Nothing,
    TurtleShield,
    IronShield,
};

enum class WeaponID {
    Nothing,
    SimpleArc,
    CompoundArc,
    LongSword,
    Hammer,
    Ax,
    ElficFlaute,
    AshStick,
    GnarledStick,
    Crosier,
};

enum class ItemsInventoryID {

};

enum class Direction{
    down,
    up,
    left,
    right,
};

#endif