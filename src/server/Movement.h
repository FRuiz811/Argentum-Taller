#ifndef ARGENTUM_TALLER_MOVEMENT_H
#define ARGENTUM_TALLER_MOVEMENT_H


#include <cstdint>
#include "../common/Identificators.h"
#include "GameStatsConfig.h"

class Movement {
private:
    bool finalized;
    bool initialized;
    Point firstPoint;
    Direction direction;
    float distance{0.0};
    uint8_t amountSteps{0};
    uint8_t actualStep{0};
public:
    Movement();
    bool isOver() const;
    bool hasStart() const;

    void start(Point aFirstPoint, Direction aDirection, RaceID raceId);
    void start(Point aFirstPoint, Direction aDirection, CreatureID creatureId);

    void reset();

    void stop();

    Point doStep();


    virtual ~Movement();

};


#endif //ARGENTUM_TALLER_MOVEMENT_H
