#include "PlayerInfo.h"

#include <utility>

PlayerInfo::PlayerInfo() {}

PlayerInfo::~PlayerInfo() {

}

uint PlayerInfo::getId() const {
    return id;
}

uint PlayerInfo::getGoldAmount() const {
    return goldAmount;
}

uint PlayerInfo::getLife() const {
    return life;
}

uint PlayerInfo::getMana() const {
    return mana;
}

const std::string &PlayerInfo::getTextureHashId() const {
    return textureHashId;
}

PlayerInfo &PlayerInfo::operator=(PlayerInfo &&other) noexcept {
    if (&other == this) {
        return *this;
    }
    std::swap(id, other.id);
    std::swap(goldAmount, other.goldAmount);
    std::swap(life, other.life);
    std::swap(mana, other.mana);
    std::swap(x, other.x);
    std::swap(y, other.y);
    std::swap(textureHashId, other.textureHashId);

    return *this;
}

PlayerInfo::PlayerInfo(PlayerInfo &&other) noexcept {
    std::swap(id, other.id);
    std::swap(goldAmount, other.goldAmount);
    std::swap(life, other.life);
    std::swap(mana, other.mana);
    std::swap(x, other.x);
    std::swap(y, other.y);
    std::swap(textureHashId, other.textureHashId);
}

int PlayerInfo::getX() const {
    return x;
}

int PlayerInfo::getY() const {
    return y;
}

PlayerInfo::PlayerInfo(uint id, int x, int y, uint goldAmount, uint life, uint mana, std::string textureHashId)
        : id(id), x(x), y(y), goldAmount(goldAmount), life(life), mana(mana), textureHashId(std::move(textureHashId)) {}
