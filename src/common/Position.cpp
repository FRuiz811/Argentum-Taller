#include "Position.h"

Position::~Position()= default;

Position::Position() = default;

Position::Position(Point &aPoint, float aWidth, float aHeight):
        x(aPoint.x), y(aPoint.y), width(aWidth), height(aHeight) {}

Position::Position(float x, float y, float width, float height):
x(x), y(y), width(width), height(height){}

float Position::getBottom() const {
    return y + height;
}

float Position::getTop() const {
    return y;
}

float Position::getRight() const {
    return x + width;
}

float Position::getLeft() const {
    return x;
}

Point Position::getPoint() const {
    return Point(x,y);
}

float Position::getWidth() const {
    return width;
}

float Position::getHeight() const {
    return height;
}

float Position::distance(Position &other) {
    return getPoint().distance(other.getPoint());
}

float Position::getMiddle() const {
    return getTop() + height/2;
}



