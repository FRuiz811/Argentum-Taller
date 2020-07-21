#ifndef ARGENTUM_TALLER_MOVEMENTCREATURE_H
#define ARGENTUM_TALLER_MOVEMENTCREATURE_H


#include "Movement.h"

class MovementCreature : public Movement {
private:
    CreatureID creatureId = CreatureID::Nothing;
public:
    MovementCreature();

    void start(Point aFirstPoint, Direction aDirection, CreatureID creatureId);

    virtual ~MovementCreature();

    float getAmountMovement() override;
};


#endif //ARGENTUM_TALLER_MOVEMENTCREATURE_H
