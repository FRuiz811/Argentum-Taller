#ifndef ARGENTUM_TALLER_NESTPOINT_H
#define ARGENTUM_TALLER_NESTPOINT_H


#include "StaticObject.h"

class NestPoint {
private:
    Point point;
    uint8_t amountCreatures = 0;
    uint8_t nestLimit;
public:
    explicit NestPoint(Point point, uint8_t nestLimit);

    virtual ~NestPoint();

    const Point &getPoint() const;

    bool isFull() const;

    void addCreature();
};


#endif //ARGENTUM_TALLER_NESTPOINT_H
