#ifndef ARGENTUM_TALLER_NESTPOINT_H
#define ARGENTUM_TALLER_NESTPOINT_H


#include <vector>
#include <memory>
#include "Position.h"

class NestPoint {
private:
    uint nestId;
    Position position;
    std::vector<uint> creatures;
    uint8_t nestLimit;
public:
    explicit NestPoint(Point point, uint width, uint height, uint8_t nestLimit, uint nestId);

    ~NestPoint();

    std::vector<Position> getPosiblePositions();

    Position &getPosition();

    void addCreature(uint id);

    uint getNestId() const;

    const std::vector<uint> &getCreatures() const;

    bool isFull() const;
};


#endif //ARGENTUM_TALLER_NESTPOINT_H
