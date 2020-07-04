#include "NestPoint.h"
#include "Exception.h"

NestPoint::NestPoint(Point point, uint8_t nestLimit): point(point), nestLimit(nestLimit){}

bool NestPoint::isFull() const {
    return amountCreatures == nestLimit;
}

void NestPoint::addCreature() {
    amountCreatures++;
}

const Point &NestPoint::getPoint() const {
    return point;
}


NestPoint::~NestPoint() = default;
