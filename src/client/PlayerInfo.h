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
    Direction direction;

public:
    PlayerInfo();
    PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana, std::string textureHashId, Direction direction);

    ~PlayerInfo() override;

    void changeDirection(Direction newDirection);

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;

    Direction getDirection() const;

    HelmetID getHelmetID() const ;
    HeadID getHeadID() const ;
    BodyID getBodyID() const ;
    WeaponID getWeaponID() const ;
    ShieldID getShieldID() const ;
};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
