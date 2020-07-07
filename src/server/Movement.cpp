#include "Movement.h"

Movement::Movement() : finalized(false), initialized(false) {}

Movement::~Movement() {}

bool Movement::isOver() {
    return finalized;
}

bool Movement::hasStart() {
    return initialized;
}

void Movement::start(Position aFirstPosition, Direction aDirection, GameStatsConfig &gameStatsConfig, RaceID raceId) {
    amountSteps = gameStatsConfig.getAmountSteps(raceId);
    distance = gameStatsConfig.getDistance();
    direction = aDirection;
    firstPosition = aFirstPosition;
    initialized = true;
}

void Movement::start(Position aFirstPosition, Direction aDirection, GameStatsConfig &gameStatsConfig, CreatureID creatureId) {
    amountSteps = gameStatsConfig.getAmountSteps(creatureId);;
    distance = gameStatsConfig.getDistance();
    direction = aDirection;
    firstPosition = aFirstPosition;
    initialized = true;
}

void Movement::reset() {
    amountSteps = 0;
    actualStep = 0;
    initialized = false;
    finalized = false;
}

Position Movement::doStep() {
    Point newPoint = firstPosition.getPoint();
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
    return Position(newPoint, firstPosition.getWidth(), firstPosition.getHeight());
}

void Movement::stop() {
    finalized = true;
}
