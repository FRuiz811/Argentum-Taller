#include <algorithm>
#include "Position.h"

Position::~Position()= default;

Position::Position() = default;

Position::Position(int x, int y, int width, int height):
x(x), y(y), width(width), height(height){}

Position::Position(Position &&other) noexcept {
    std::swap(x, other.x);
    std::swap(y, other.y);
    std::swap(width, other.width);
    std::swap(height, other.height);
}

Position &Position::operator=(Position &&other) noexcept {
    if (&other == this) {
        return *this;
    }
    std::swap(x, other.x);
    std::swap(y, other.y);
    std::swap(width, other.width);
    std::swap(height, other.height);
    return *this;
}

int Position::getBottom() const {
    return y + height;
}

int Position::getTop() const {
    return y;
}

int Position::getRight() const {
    return x + width;
}

int Position::getLeft() const {
    return x;
}




