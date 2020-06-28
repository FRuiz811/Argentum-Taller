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
    mana(mana) {
        this->inventory = "02|06|12|16|09|05|21|00|00";
    }

PlayerInfo::PlayerInfo() : GameObjectInfo() {}

Direction PlayerInfo::getDirection() const {
    return this->direction;
}

uint PlayerInfo::getMaxExp() const {
    return this->maxExp;
}

uint PlayerInfo::getMaxLife() const {
    return this->maxLife;
}

uint PlayerInfo::getMaxMana() const {
    return this->maxMana;
}

uint PlayerInfo::getSafeGold() const {
    return this->safeGold;
}

uint PlayerInfo::getExp() const {
    return this->exp;
}

uint PlayerInfo::getLevel() const {
    return this->level;
}

std::string PlayerInfo::getInventory() const {
    return this->inventory;
}