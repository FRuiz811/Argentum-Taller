#include "NestPointContainer.h"
#include "Exception.h"

#include <utility>

NestPointContainer::NestPointContainer(std::vector<NestPoint> nestPoints) : nestPoints(std::move(nestPoints)) {
    length = nestPoints.size();
}

Point NestPointContainer::getNextNestPointAvailable() {
    uint8_t initPos = pos;
    NestPoint nestPoint = nestPoints.at(pos++);
    while (nestPoint.isFull() && pos != initPos) {
        if (pos == length) {
            pos = 0;
        }
        nestPoint = nestPoints.at(pos++);
    }
    if (nestPoint.isFull()) {
        throw Exception("There is not available points to add creatures");
    }
    nestPoint.addCreature();
    return nestPoint.getPoint();
}

NestPointContainer::NestPointContainer() = default;

NestPointContainer::~NestPointContainer() = default;
