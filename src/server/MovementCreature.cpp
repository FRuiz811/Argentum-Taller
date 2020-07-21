#include "MovementCreature.h"

MovementCreature::MovementCreature() : Movement() {}

MovementCreature::~MovementCreature() = default;

void MovementCreature::start(Point aFirstPoint, Direction aDirection, CreatureID aCreatureId) {
    creatureId = aCreatureId;
    partialDistance = 0.0f;
    distance = GameStatsConfig::getDistance();
    direction = aDirection;
    firstPoint = aFirstPoint;
    initialized = true;
}
