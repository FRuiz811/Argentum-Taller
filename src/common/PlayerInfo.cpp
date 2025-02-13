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

PlayerInfo::PlayerInfo(uint id, Point point, uint goldAmount, uint life, uint mana, const std::string& textureHashId,
    Direction direction, uint safeGold, uint maxLife, uint maxMana, uint exp, uint maxExp,
    uint level,std::string  inventory, CharacterStateID state, WeaponID attackBy)
    :GameObjectInfo(id, point, textureHashId, direction,state, false ,attackBy),
    goldAmount(goldAmount), life(life), mana(mana), level(level), exp(exp), maxLife(maxLife),
    maxMana(maxMana), maxExp(maxExp), safeGold(safeGold) , inventory(std::move(inventory)) {}

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

std::string PlayerInfo::getName() const {
    return this->name;
}

std::string PlayerInfo::getInventory() const {
    return this->inventory;
}
