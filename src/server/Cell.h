#ifndef ARGENTUM_TALLER_CELL_H
#define ARGENTUM_TALLER_CELL_H

#include <zconf.h>

class Cell {
private:
    uint x;
    uint y;
    bool empty;
    uint gameObjectId;
    bool city;
    uint nestId;
public:
    Cell(uint x, uint y);

    void occupied(uint id);

    void free();

    std::tuple<int, int> getCoord();

    bool isEmpty() const;

    void setEmpty(bool empty);

    uint getGameObjectId() const;

    bool isCity() const;

    void setCity(bool city);

    uint getNestId() const;

    void setNestId(uint nestId);

    uint getX() const;

    uint getY() const;

    virtual ~Cell();

};


#endif //ARGENTUM_TALLER_CELL_H
