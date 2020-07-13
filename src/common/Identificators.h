#ifndef CHARACTERSTATESID_H
#define CHARACTERSTATESID_H

#include "Point.h"
#include <vector>
#include <unordered_map>
#include <iostream>

enum class CharacterStateID {
    Still, //Aplica a NPCServer
    Move,  //Aplica a NPCServer
    Attack, //Aplica a NPCServer
    Meditate,
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
    buy,      
    sell,      
    depositItem,  
    retireItem,
    depositGold,
    retireGold, 
    selectTarget, //click
    equipItem,
    dropItem, 
    takeItem, //t
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
    Human,
    Elf,
    Dwarf,
    Gnome,
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
    Gold,
};

enum class Direction{
    down,
    up,
    left,
    right,
};

enum class RaceID {
    Nothing,
    Human,
    Elf,
    Dwarf,
    Gnome
};

enum class GameClassID {
    Nothing,
    Mage,
    Cleric,
    Paladin,
    Warrior
};

enum class CreatureID {
    Nothing,
    Zombie,
    Skeleton,
    Spider,
    Goblin,
};

enum class ActionsProfessionID {
    Nothing,
    DepositItem,
    DepositGold,
    RetireItem,
    RetireGold,
    Buy,
    Sell,
    Resurrect,
    Cure,
};

struct NPCInfo {
    uint8_t type = 0;
    std::vector<ActionsProfessionID> actions;
    std::unordered_map<ItemsInventoryID,uint> items;
    uint32_t gold;
    std::vector<ItemsInventoryID> itemsInBank;
};

struct InputInfo {
    InputID input = InputID::nothing;
    Point position;
    int aditional = 0;
};

#endif
