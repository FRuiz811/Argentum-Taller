#ifndef ARGENTUM_TALLER_PLAYERINFO_H
#define ARGENTUM_TALLER_PLAYERINFO_H

#include <zconf.h>
#include <string>
#include "../common/Position.h"

class PlayerInfo {
private:
    uint id{};
    int x;
    int y;
    uint goldAmount{};
    uint life{};
    uint mana{};
    std::string textureHashId;

public:
    PlayerInfo();

    PlayerInfo(uint id, int x, int y, uint goldAmount, uint life, uint mana, std::string textureHashId);

    ~PlayerInfo();

    PlayerInfo(PlayerInfo&& other) noexcept ;
    PlayerInfo& operator=(PlayerInfo&& other) noexcept ;

    uint getId() const;

    int getX() const;

    int getY() const;

    uint getGoldAmount() const;

    uint getLife() const;

    uint getMana() const;

    const std::string &getTextureHashId() const;

};


#endif //ARGENTUM_TALLER_PLAYERINFO_H
