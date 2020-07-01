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

void Position::setX(float x) {
    Position::x = x;
}

void Position::setY(float y) {
    Position::y = y;
}

void Position::setWidth(float width) {
    Position::width = width;
}

void Position::setHeight(float height) {
    Position::height = height;
}

Point Position::getPoint() const {
    return Point(x,y);
}

int Position::getWidth() const {
    return width;
}

int Position::getHeight() const {
    return height;
}




