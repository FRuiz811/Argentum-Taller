#include "GameObjectInfo.h"
#include <utility>

GameObjectInfo::~GameObjectInfo() = default;

GameObjectInfo::GameObjectInfo(uint id, const Point &point, std::string textureHashId, Direction aDirection,
     CharacterStateID state, bool item, WeaponID attackBy) : id(id), point(point), textureHashId(std::move(textureHashId)),
     direction(aDirection), state(state), item(item), attackBy(attackBy) {}

uint GameObjectInfo::getId() const {
    return id;
}

const Point &GameObjectInfo::getPoint() const {
    return point;
}

const std::string &GameObjectInfo::getTextureHashId() const {
    return textureHashId;
}

float GameObjectInfo::getX() const {
    return point.x;
}

float GameObjectInfo::getY() const {
    return point.y;
}

HelmetID GameObjectInfo::getHelmetID() const {
    std::string stringId = this->textureHashId.substr(2,2);
    int id = std::stoi(stringId);
    return (HelmetID)id;
}

HeadID GameObjectInfo::getHeadID() const {
    std::string stringId = this->textureHashId.substr(6,2);
    int id = std::stoi(stringId);
    return (HeadID)id;
}

BodyID GameObjectInfo::getBodyID() const {
    std::string stringId = this->textureHashId.substr(10,2);
    int id = std::stoi(stringId);
    return (BodyID)id;
}
WeaponID GameObjectInfo::getWeaponID() const {
    std::string stringId = this->textureHashId.substr(18,2);
    int id = std::stoi(stringId);
    return (WeaponID)id;
}
ShieldID GameObjectInfo::getShieldID() const {
    std::string stringId = this->textureHashId.substr(14,2);
    int id = std::stoi(stringId);
    return (ShieldID)id;
}

ItemsInventoryID GameObjectInfo::getItemID() const {
    std::string stringId = this->textureHashId.substr(22,2);
    int id = std::stoi(stringId);
    return (ItemsInventoryID)id;
}

Direction GameObjectInfo::getDirection() const {
    return direction;
}

bool GameObjectInfo::isItem() const {
    return this->item;
}

CharacterStateID GameObjectInfo::getState() const {
    return this->state;
}

WeaponID GameObjectInfo::getAttackWeapon() const {
    return this->attackBy;
}

GameObjectInfo::GameObjectInfo() = default;
