#ifndef ARGENTUM_TALLER_NEST_H
#define ARGENTUM_TALLER_NEST_H


#include <vector>
#include <memory>
#include "Cell.h"

class Nest {
private:
    uint8_t nestLimit;
    uint nestId;
    std::vector<std::shared_ptr<Cell>> nestCells;
    std::vector<uint> creatures;

public:
    explicit Nest(uint8_t nestLimit, uint nestId, std::vector<std::shared_ptr<Cell>> cells);

    ~Nest();

    void addCreature(uint id);

    std::shared_ptr<Cell> getFreeCell();

    friend bool operator<(const Nest& firstNest, const Nest& secondNest);

    uint getNestId() const;

    const std::vector<uint> &getCreatures() const;

    int getAmountCreatures() const ;

    void removeCreature(uint id);

    bool isFull() const;
};


#endif //ARGENTUM_TALLER_NEST_H
