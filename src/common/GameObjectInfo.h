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
    CharacterStateID state;
    bool item;
    WeaponID attackBy;
public:
    GameObjectInfo();
    GameObjectInfo(uint id, const Point &point, std::string textureHashId, Direction direction, 
        CharacterStateID state, bool item, WeaponID attackBy);

    const Point &getPoint() const;

    const std::string &getTextureHashId() const;

    virtual ~GameObjectInfo();

    uint getId() const;

    float getX() const;

    float getY() const;

    Direction getDirection() const;

    HelmetID getHelmetID() const;
    HeadID getHeadID() const;
    BodyID getBodyID() const;
    WeaponID getWeaponID() const;
    ShieldID getShieldID() const;
    ItemsInventoryID getItemID() const;
    CharacterStateID getState() const;
    WeaponID getAttackWeapon() const;

    bool isItem() const;
};


#endif //ARGENTUM_TALLER_GAMEOBJECTINFO_H
