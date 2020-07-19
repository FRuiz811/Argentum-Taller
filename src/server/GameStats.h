#ifndef ARGENTUM_TALLER_GAMESTATS_H
#define ARGENTUM_TALLER_GAMESTATS_H

#include <cstdint>

struct RaceInfo {
    float intelligent;
    float recoveryTime;
    float health;
    float mana;
    float constitution;
    float strength;
    float agility;
};

struct GameClassInfo {
    float health;
    float mana;
    float meditation;
};

struct ItemInfo {
    uint8_t id;
    std::string name;
    bool damage;
    uint8_t range;
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

struct CreatureInfo {
    float health;
    float strength;
    float agility;
    float constitution;
};

#endif //ARGENTUM_TALLER_GAMESTATS_H
