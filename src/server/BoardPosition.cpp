#include "BoardPosition.h"

BoardPosition::BoardPosition(const Position &position, const uint &nestId, bool insideCity) :
position(position), nestId(nestId), insideCity(insideCity) {}

Position &BoardPosition::getPosition() {
    return position;
}

uint BoardPosition::getNestId() const {
    return nestId;
}

bool BoardPosition::isInsideCity() const {
    return insideCity;
}

void BoardPosition::setPosition(const Position &position) {
    BoardPosition::position = position;
}

void BoardPosition::setNestId(uint nestId) {
    BoardPosition::nestId = nestId;
}

void BoardPosition::setInsideCity(bool insideCity) {
    BoardPosition::insideCity = insideCity;
}

BoardPosition::BoardPosition() = default;

BoardPosition::~BoardPosition() = default;
