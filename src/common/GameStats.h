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

#endif //ARGENTUM_TALLER_GAMESTATS_H
