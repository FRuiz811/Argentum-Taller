#include "MovementCharacter.h"

MovementCharacter::MovementCharacter() : Movement() {}

MovementCharacter::~MovementCharacter() = default;

void MovementCharacter::start(Point aFirstPoint, Direction aDirection, RaceID aRaceId) {
    raceId = aRaceId;
    partialDistance = 0.0f;
    distance = GameStatsConfig::getDistance();
    direction = aDirection;
    firstPoint = aFirstPoint;
    initialized = true;
}

float MovementCharacter::getAmountMovement() {
    return GameStatsConfig::getAmountMovement(raceId);
}
