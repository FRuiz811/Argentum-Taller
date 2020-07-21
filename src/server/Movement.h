#ifndef ARGENTUM_TALLER_MOVEMENT_H
#define ARGENTUM_TALLER_MOVEMENT_H


#include <cstdint>
#include "../common/Identificators.h"
#include "GameStatsConfig.h"

class Movement {
protected:
    bool finalized;
    bool initialized;
    Point firstPoint;
    Direction direction;
    float distance;
    float partialDistance;
public:
    Movement();
    bool isOver() const;
    bool hasStart() const;



    void reset();

    void stop();

    Point doStep();


    virtual ~Movement();

};


#endif //ARGENTUM_TALLER_MOVEMENT_H
