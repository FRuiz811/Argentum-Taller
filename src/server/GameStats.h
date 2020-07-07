#ifndef ARGENTUM_TALLER_GAMESTATS_H
#define ARGENTUM_TALLER_GAMESTATS_H

#include <cstdint>

struct RaceInfo {
    uint8_t intelligent;
    uint8_t recoveryTime;
    uint8_t health;
    uint8_t mana;
    uint8_t constitution;
    uint8_t strength;
    uint8_t agility;
};

struct GameClassInfo {
    uint8_t health;
    uint8_t mana;
    uint8_t meditation;
};

struct ItemInfo {
    uint8_t id;
    std::string name;
    bool damage;
    bool hasRange;
    uint8_t minDamage;
    uint8_t maxDamage;
    uint8_t manaUsed;
    uint8_t manaRestored;
    uint8_t healthRestored;
    uint8_t minDefense;
    uint8_t maxDefense;
    uint8_t goldCost;
    std::string type; 
};

#endif //ARGENTUM_TALLER_GAMESTATS_H
