#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "GameObjectInfo.h"
#include "Identificators.h"

class PlayerInfo : public GameObjectInfo{
private:
    uint goldAmount{};
    uint life{};
    uint mana{};
    uint level{};
    uint exp{};
    uint maxLife{};
    uint maxMana{};
    uint maxExp{};
    uint safeGold{};
    std::string inventory;
    std::string name;

public:
    PlayerInfo();
    PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana,
        const std::string& textureHashId, Direction direction,uint safeGold, 
        uint maxLife, uint maxMana, uint exp, uint maxExp, uint level,
        std::string  inventory, CharacterStateID state, WeaponID attackBy);

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

    std::string getName() const;

    std::string getInventory() const;
};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
