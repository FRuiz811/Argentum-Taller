#include "Movement.h"

Movement::Movement() : finalized(false), initialized(false) {}

Movement::~Movement() = default;

bool Movement::isOver() const {
    return finalized;
}

bool Movement::hasStart() const {
    return initialized;
}

void Movement::start(Point aFirstPoint, Direction aDirection, GameStatsConfig &gameStatsConfig, RaceID raceId) {
    amountSteps = gameStatsConfig.getAmountSteps(raceId);
    actualStep = 0;
    distance = gameStatsConfig.getDistance();
    direction = aDirection;
    firstPoint = aFirstPoint;
    initialized = true;
}

void Movement::start(Point aFirstPoint, Direction aDirection, GameStatsConfig &gameStatsConfig, CreatureID creatureId) {
    amountSteps = gameStatsConfig.getAmountSteps(creatureId);
    actualStep = 0;
    distance = gameStatsConfig.getDistance();
    direction = aDirection;
    firstPoint = aFirstPoint;
    initialized = true;
}

void Movement::reset() {
    amountSteps = 0;
    actualStep = 0;
    initialized = false;
    finalized = false;
}

Point Movement::doStep() {
    Point newPoint = firstPoint;
    switch(direction) {
        case Direction::up:
            newPoint.y -= (distance/amountSteps) * actualStep;
            break;
        case Direction::down:
            newPoint.y += (distance/amountSteps) * actualStep;
            break;
        case Direction::left:
            newPoint.x -= (distance/amountSteps) * actualStep;
            break;
        case Direction::right:
            newPoint.x += (distance/amountSteps) * actualStep;
            break;
    }
    actualStep++;
    if (actualStep >= amountSteps) {
        finalized = true;
    }
    return newPoint;
}

void Movement::stop() {
    finalized = true;
}
