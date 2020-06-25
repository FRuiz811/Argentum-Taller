#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "../common/Position.h"
#include "../common/Identificators.h"

class PlayerInfo {
private:
    uint id{};
    int x;
    int y;
    uint goldAmount{};
    uint life{};
    uint mana{};
    std::string textureHashId;
    Direction direction;

public:
    PlayerInfo();

    PlayerInfo(uint id, int x, int y, uint goldAmount, uint life, uint mana, std::string textureHashId, Direction direction);

    ~PlayerInfo();

    //PlayerInfo(PlayerInfo&& other) noexcept ;
    //PlayerInfo& operator=(PlayerInfo&& other) noexcept ;

    uint getId() const;

    int getX() const;

    int getY() const;

    void setX(uint x);

    void setY(uint y);

    void changeDirection(Direction newDirection);

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;

    Direction getDirection() const;

    const std::string &getTextureHashId() const;

    HelmetID getHelmetID();
    HeadID getHeadID();
    BodyID getBodyID();
    WeaponID getWeaponID();
    ShieldID getShieldID();
};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
