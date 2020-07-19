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
    uint itemId;
    bool priest;
public:
    Cell(uint x, uint y);

    void occupied(uint id);

    void free();

    std::tuple<int, int> getCoord();

    friend bool operator==(const Cell& c1, const Cell& c2);

    friend bool operator!=(const Cell& c1, const Cell& c2);

    void removeItem();

    bool hasItem() const;

    void setItemId(uint itemId);

    uint getItemId() const;

    bool isEmpty() const;

    bool isPriest() const;

    void setPriest(bool priest);

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
