#include <tuple>
#include "Cell.h"

Cell::Cell(uint x, uint y) : x(x), y(y), empty(true), gameObjectId(0), city(false), nestId(0), itemId(0), priest(false) {}

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

bool operator==(const Cell& c1, const Cell &c2) {
    return c1.x == c2.x && c1.y == c2.y;
}

bool operator!=(const Cell& c1, const Cell &c2) {
    return !(c1==c2);
}

void Cell::removeItem() {
    itemId = 0;
}

uint Cell::getItemId() const {
    return itemId;
}

bool Cell::hasItem() const {
    return itemId != 0;
}

void Cell::setItemId(uint itemId) {
    Cell::itemId = itemId;
}

bool Cell::isPriest() const {
    return priest;
}

void Cell::addPriest() {
    priest = true;
}


Cell::~Cell() = default;
