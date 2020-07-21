#ifndef ARGENTUM_TALLER_MOVEMENTCHARACTER_H
#define ARGENTUM_TALLER_MOVEMENTCHARACTER_H


#include "Movement.h"

class MovementCharacter : public Movement {
private:
    RaceID raceId = RaceID::Nothing;
public:
    MovementCharacter();

    void start(Point aFirstPoint, Direction aDirection, RaceID raceId);

    ~MovementCharacter() override;

};


#endif //ARGENTUM_TALLER_MOVEMENTCHARACTER_H
