#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "../common/Position.h"
#include "../common/GameObjectInfo.h"
#include "../common/Identificators.h"

class PlayerInfo : public GameObjectInfo{
private:
    uint goldAmount{};
    uint life{};
    uint mana{};
    uint level{2};
    uint exp{125};
    uint maxLife{100};
    uint maxMana{100};
    uint maxExp{1500};
    uint safeGold{50};
    std::string inventory;

public:
    PlayerInfo();
    PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana, std::string textureHashId, Direction direction);

    ~PlayerInfo() override;

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;

    Direction getDirection() const;

    uint getExp() const;

    uint getLevel() const;

    uint getSafeGold() const;

    uint getMaxLife() const;

    uint getMaxMana() const;

    uint getMaxExp() const;

    std::string getInventory() const;
};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
