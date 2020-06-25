#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "../common/Position.h"
#include "../common/GameObjectInfo.h"

class PlayerInfo : public GameObjectInfo{
private:
    uint goldAmount{};
    uint life{};
    uint mana{};

public:
    PlayerInfo();
    PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana, std::string textureHashId);

    ~PlayerInfo() override;

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;
};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
