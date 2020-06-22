//
// Created by victorbelosevich on 21/6/20.
//

#ifndef ARGENTUM_TALLER_COLLIDER_H
#define ARGENTUM_TALLER_COLLIDER_H


#include "Position.h"

class Collider {
public:
    Collider();

    virtual ~Collider();

    static bool checkCollision(const Position&, const Position&);

};


#endif //ARGENTUM_TALLER_COLLIDER_H
