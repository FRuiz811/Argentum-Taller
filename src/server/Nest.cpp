#include "Nest.h"
#include <utility>

Nest::Nest(uint8_t nestLimit, uint nestId, std::vector<std::shared_ptr<Cell>> cells):
nestLimit(nestLimit), nestId(nestId), nestCells(std::move(cells)) {}

bool Nest::isFull() const {
    bool isFull = creatures.size() == nestLimit;
    if (!isFull) {
        isFull = true;
        for (auto &aCell : nestCells) {
            if (aCell->isEmpty()) {
                isFull = false;
                break;
            }
        }
    }
    return isFull;
}

std::shared_ptr<Cell> Nest::getFreeCell() {
    std::shared_ptr<Cell> returnedCell;
    for (auto &cell : nestCells) {
        if (cell->isEmpty()) {
            returnedCell = cell;
        }
    }
    return returnedCell;
}

void Nest::addCreature(uint id) {
    creatures.push_back(id);
}

const std::vector<uint> &Nest::getCreatures() const {
    return creatures;
}

uint Nest::getNestId() const {
    return nestId;
}

void Nest::removeCreature(uint id) {
    auto iter = creatures.begin();
    while (iter != creatures.end()) {
        if ((*iter) == id) {
            iter = this->creatures.erase(iter);
        } else {
            iter++;
        }
    }
}

int Nest::getAmountCreatures() const {
    return creatures.size();
}

bool operator<(const Nest& firstNest,const Nest &secondNest) {
    return firstNest.getAmountCreatures() < secondNest.getAmountCreatures();
}


Nest::~Nest() = default;
