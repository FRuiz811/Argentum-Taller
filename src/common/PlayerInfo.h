#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "../common/Position.h"
#include "../common/GameObjectInfo.h"
#include "../common/Identificators.h"

class PlayerInfo : public GameObjectInfo{
private:
    uint goldAmount{0};
    uint life{100};
    uint mana{100};
    uint level{1};
    uint exp{0};
    uint maxLife{100};
    uint maxMana{100};
    uint maxExp{1000};
    uint safeGold{50};
    std::string inventory;
    std::string name;

public:
    PlayerInfo();
    PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana,const std::string& textureHashId, Direction direction,
        uint safeGold, uint maxLife, uint maxMana, uint exp, uint maxExp, uint level,const std::string& inventory, CharacterStateID state);

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
