#ifndef ARGENTUM_TALLER_BOARDPOSITION_H
#define ARGENTUM_TALLER_BOARDPOSITION_H


#include <zconf.h>
#include "Position.h"

class BoardPosition {
private:
    Position position;
    uint nestId{};
    bool insideCity{};
public:
    BoardPosition();

    BoardPosition(const Position &position, const uint &nestId, bool insideCity);

    virtual ~BoardPosition();

    Position &getPosition();

    uint getNestId() const;

    bool isInsideCity() const;

    void setPosition(const Position &position);

    void setNestId(uint nestId);

    void setInsideCity(bool insideCity);
};


#endif //ARGENTUM_TALLER_BOARDPOSITION_H
