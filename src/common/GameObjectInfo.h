#ifndef ARGENTUM_TALLER_GAMEOBJECTINFO_H
#define ARGENTUM_TALLER_GAMEOBJECTINFO_H


#include <zconf.h>
#include <string>
#include "Position.h"
#include "Identificators.h"

class GameObjectInfo {
protected:
    uint id{};
    Point point;
    Direction direction;
    std::string textureHashId;
public:
    GameObjectInfo();
    GameObjectInfo(uint id, const Point &point, std::string textureHashId, Direction direction);

    const Point &getPoint() const;

    const std::string &getTextureHashId() const;

    virtual ~GameObjectInfo();

    uint getId() const;

    uint getX() const;

    uint getY() const;

    Direction getDirection() const;

    HelmetID getHelmetID() const;
    HeadID getHeadID() const;
    BodyID getBodyID() const;
    WeaponID getWeaponID() const;
    ShieldID getShieldID() const;

};


#endif //ARGENTUM_TALLER_GAMEOBJECTINFO_H
