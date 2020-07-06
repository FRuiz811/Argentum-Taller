#include <ctime>
#include "NestPoint.h"

NestPoint::NestPoint(Point point, uint width, uint height, uint8_t nestLimit, uint nestId): nestLimit(nestLimit), nestId(nestId) {
    Point nestPoint;
    nestPoint.x = (point.x - 250) >= 0 ? point.x - 250 : 0;
    nestPoint.y = (point.y - 250) >= 0 ? point.y - 250 : 0;
    float nestWidth = (nestPoint.x + 500) <=  width ? 500 : width - nestPoint.x;
    float nestHeight = (nestPoint.y + 500) <=  height ? 500 : height - nestPoint.y;
    position = Position(nestPoint, nestWidth, nestHeight);
}

bool NestPoint::isFull() const {
    return creatures.size() == nestLimit;
}

std::vector<Position> NestPoint::getPosiblePositions() {
    std::vector<Position> posiblePositions;
    for (size_t i = position.getTop(); i < position.getBottom(); i +=100) {
        for (size_t j = position.getLeft(); j < position.getRight(); j += 100) {
            if (position.getRight() - j > 100 && position.getBottom() - i > 100) {
                posiblePositions.emplace_back(j, i, 100, 100);
            }
        }
    }
    return posiblePositions;
}

void NestPoint::addCreature(uint id) {
    creatures.push_back(id);
}

Position &NestPoint::getPosition() {
    return position;
}

const std::vector<uint> &NestPoint::getCreatures() const {
    return creatures;
}

uint NestPoint::getNestId() const {
    return nestId;
}

NestPoint::~NestPoint() = default;
