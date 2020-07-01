#ifndef CHARACTERSTATESID_H
#define CHARACTERSTATESID_H

#include "Point.h"

enum class CharacterStateID {
    Still, //Aplica a NPCServer
    Move,  //Aplica a NPCServer
    Attack, //Aplica a NPCServer
    Meditate, 
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
    meditate, //y
    resurrect, //r
    cure, //h
    buy,       //b
    sell,      //v
    deposit,   //x
    retire, //z
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
    dropItem, //g
    takeItem, //t
};

struct InputInfo {
    InputID input = InputID::nothing;
    Point position;
    int aditional = 0;
    int idPlayer;
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
    Merchant,
    Priest,
    Goblin,
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
    TurtleShield,
    IronShield,
    Hood,
    IronHelmet,
    MagicHat,
    RedCommon,
    BlueCommon,
    GreenCommon,
    BlueTunic,
    LeatherArmor,
    PlateArmor,
    HealthPotion,
    ManaPotion,
};

enum class Direction{
    down,
    up,
    left,
    right,
};

#endif