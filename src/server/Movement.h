#ifndef ARGENTUM_TALLER_MOVEMENT_H
#define ARGENTUM_TALLER_MOVEMENT_H


#include <cstdint>
#include "../common/Identificators.h"
#include "GameStatsConfig.h"
#include "../common/Position.h"

class Movement {
private:
    bool finalized;
    bool initialized;
    Position firstPosition;
    Direction direction;
    float distance;
    uint8_t amountSteps = 0;
    uint8_t actualStep = 0;
public:
    Movement();
    bool isOver();
    bool hasStart();

    void start(Position aFirstPosition, Direction aDirection, GameStatsConfig& gameStatsConfig, RaceID raceId);
    void start(Position aFirstPosition, Direction aDirection, GameStatsConfig& gameStatsConfig, CreatureID creatureId);

    void reset();

    void stop();

    Position doStep();


    virtual ~Movement();

};


#endif //ARGENTUM_TALLER_MOVEMENT_H
