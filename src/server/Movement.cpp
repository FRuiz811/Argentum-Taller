#include "Movement.h"

Movement::Movement() : finalized(false), initialized(false), firstPoint(0.0,0.0),
    direction(Direction::down), distance(0), partialDistance(0) {}

Movement::~Movement() = default;

bool Movement::isOver() const {
    return finalized;
}

bool Movement::hasStart() const {
    return initialized;
}

void Movement::reset() {
    partialDistance = 0.0f;
    initialized = false;
    finalized = false;
}

Point Movement::doStep() {
    Point newPoint = firstPoint;
//    partialDistance = partialDistance;
    switch(direction) {
        case Direction::up:
            newPoint.y = partialDistance;
            break;
        case Direction::down:
            newPoint.y = partialDistance;
            break;
        case Direction::left:
            newPoint.x = partialDistance;
            break;
        case Direction::right:
            newPoint.x = partialDistance;
            break;
    }
    if (partialDistance >=  distance) {
        finalized = true;
    }
    return newPoint;
}

void Movement::stop() {
    finalized = true;
}
