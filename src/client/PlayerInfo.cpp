#include "PlayerInfo.h"

#include <utility>

PlayerInfo::~PlayerInfo() = default;

uint PlayerInfo::getGoldAmount() const {
    return goldAmount;
}

uint PlayerInfo::getLife() const {
    return life;
}

uint PlayerInfo::getMana() const {
    return mana;
}

PlayerInfo::PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana, std::string textureHashId, Direction direction):
    GameObjectInfo(id, point, std::move(textureHashId)),
    goldAmount(goldAmount),
    life(life),
    mana(mana),
    direction(direction) {}

PlayerInfo::PlayerInfo() : GameObjectInfo() {}

Direction PlayerInfo::getDirection() const {
    return this->direction;
}

void PlayerInfo::changeDirection(Direction newDirection) {
    this->direction = newDirection;
}

HelmetID PlayerInfo::getHelmetID() const {
    std::string stringId = this->textureHashId.substr(2,2);
    int id = std::stoi(stringId);
    return (HelmetID)id;
}

HeadID PlayerInfo::getHeadID() const {
    std::string stringId = this->textureHashId.substr(6,2);
    int id = std::stoi(stringId);
    return (HeadID)id;
}

BodyID PlayerInfo::getBodyID() const {
    std::string stringId = this->textureHashId.substr(10,2);
    int id = std::stoi(stringId);
    return (BodyID)id;
}
WeaponID PlayerInfo::getWeaponID() const {
    std::string stringId = this->textureHashId.substr(14,2);
    int id = std::stoi(stringId);
    return (WeaponID)id;
}
ShieldID PlayerInfo::getShieldID() const {
    std::string stringId = this->textureHashId.substr(18,2);
    int id = std::stoi(stringId);
    return (ShieldID)id;
}