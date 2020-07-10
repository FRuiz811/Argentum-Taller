#include <tuple>
#include "Cell.h"

Cell::Cell(uint x, uint y) : x(x), y(y), empty(true), gameObjectId(0), city(false), nestId(0) {}

bool Cell::isEmpty() const {
    return empty;
}

void Cell::setEmpty(bool empty) {
    Cell::empty = empty;
}

uint Cell::getGameObjectId() const {
    return gameObjectId;
}

bool Cell::isCity() const {
    return city;
}

void Cell::setCity(bool city) {
    Cell::city = city;
}

uint Cell::getNestId() const {
    return nestId;
}

void Cell::setNestId(uint nestId) {
    Cell::nestId = nestId;
}

uint Cell::getX() const {
    return x;
}

uint Cell::getY() const {
    return y;
}

void Cell::occupied(uint id) {
    gameObjectId = id;
    empty = false;
}

void Cell::free() {
    gameObjectId = 0;
    empty = true;
}

std::tuple<int, int> Cell::getCoord() {
    return {x, y};
}

Cell::~Cell() = default;
