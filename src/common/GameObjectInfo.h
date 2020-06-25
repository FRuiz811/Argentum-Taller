#ifndef ARGENTUM_TALLER_GAMEOBJECTINFO_H
#define ARGENTUM_TALLER_GAMEOBJECTINFO_H


#include <zconf.h>
#include <string>
#include "Position.h"
#include "../client/Point.h"

class GameObjectInfo {
protected:
    uint id{};
    Point point;
    std::string textureHashId;
public:
    GameObjectInfo();
    GameObjectInfo(uint id, const Point &point, std::string textureHashId);

    const Point &getPoint() const;

    const std::string &getTextureHashId() const;

    virtual ~GameObjectInfo();

    uint getId() const;

    uint getX() const;

    uint getY() const;

};


#endif //ARGENTUM_TALLER_GAMEOBJECTINFO_H
