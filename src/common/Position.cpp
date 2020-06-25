#include "Position.h"

Position::~Position()= default;

Position::Position() = default;

Position::Position(int x, int y, int width, int height):
x(x), y(y), width(width), height(height){}

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

void Position::setX(int x) {
    Position::x = x;
}

void Position::setY(int y) {
    Position::y = y;
}

void Position::setWidth(int width) {
    Position::width = width;
}

void Position::setHeight(int height) {
    Position::height = height;
}

Point Position::getPoint() const {
    return Point(x,y);
}

Position::Position(Point &aPoint, int aWidth, int aHeight):
x(aPoint.x), y(aPoint.y), width(aWidth), height(aHeight) {}




