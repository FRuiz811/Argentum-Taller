#include "NestPointContainer.h"
#include "../client/Exception.h"

#include <utility>

NestPointContainer::NestPointContainer(std::vector<NestPoint> nestPoints) : nestPoints(std::move(nestPoints)) {
    length = nestPoints.size();
}

NestPoint& NestPointContainer::getNextNestPointAvailable() {
    uint8_t initPos = pos;
    NestPoint& nestPoint = nestPoints.at(pos++);
    while (nestPoint.isFull() && pos != initPos) {
        if (pos == length) {
            pos = 0;
        }
        nestPoint = nestPoints.at(pos++);
    }
    if (nestPoint.isFull()) {
        throw Exception("There is not available points to add creatures");
    }
    return nestPoint;
}

std::vector<NestPoint> &NestPointContainer::getNestPoints() {
    return nestPoints;
}

NestPoint &NestPointContainer::getNestPoint(uint nestId) {
    size_t index = 0;
    for (auto &aNestPoint : nestPoints) {
        if (nestId == aNestPoint.getNestId()) {
            break;
        }
        index++;
    }
    return nestPoints.at(index);
}

NestPointContainer::NestPointContainer() = default;

NestPointContainer::~NestPointContainer() = default;
