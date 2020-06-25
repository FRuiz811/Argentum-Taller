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
    GameObjectInfo(id, point, std::move(textureHashId), direction),
    goldAmount(goldAmount),
    life(life),
    mana(mana) {}

PlayerInfo::PlayerInfo() : GameObjectInfo() {}

Direction PlayerInfo::getDirection() const {
    return this->direction;
}