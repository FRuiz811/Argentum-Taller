#include "PlayerStats.h"

PlayerStats::PlayerStats(Direction direction, const uint &life, const uint &mana, const uint &goldAmount,
                         const Position &position) : direction(direction), life(life), mana(mana),
                                                     goldAmount(goldAmount), position(position) {}

Direction PlayerStats::getDirection() const {
    return direction;
}

uint PlayerStats::getLife() const {
    return life;
}

uint PlayerStats::getMana() const {
    return mana;
}

uint PlayerStats::getGoldAmount() const {
    return goldAmount;
}

const Position &PlayerStats::getPosition() const {
    return position;
}

void PlayerStats::setDirection(Direction direction) {
    PlayerStats::direction = direction;
}

void PlayerStats::setLife(uint life) {
    PlayerStats::life = life;
}

void PlayerStats::setMana(uint mana) {
    PlayerStats::mana = mana;
}

void PlayerStats::setGoldAmount(uint goldAmount) {
    PlayerStats::goldAmount = goldAmount;
}

void PlayerStats::setPosition(const Position &position) {
    PlayerStats::position = position;
}

PlayerStats::~PlayerStats() = default;
