#ifndef ARGENTUM_TALLER_GAMEOBJECTINFO_H
#define ARGENTUM_TALLER_GAMEOBJECTINFO_H


#include <zconf.h>
#include <string>
#include "Position.h"

class GameObjectInfo {
private:
    Position position;
    uint16_t goldAmount{};
    uint16_t life{};
    uint16_t mana{};
    std::string textureHashId;
};


#endif //ARGENTUM_TALLER_GAMEOBJECTINFO_H
