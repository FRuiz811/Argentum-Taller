#ifndef ARGENTUM_TALLER_NESTPOINTCONTAINER_H
#define ARGENTUM_TALLER_NESTPOINTCONTAINER_H


#include <vector>
#include "NestPoint.h"

class NestPointContainer {
private:
    std::vector<NestPoint> nestPoints;
    uint8_t pos = 0;
    uint8_t length{};
public:
    NestPointContainer();

    explicit NestPointContainer(std::vector<NestPoint> nestPoints);

    virtual ~NestPointContainer();

    Point getNextNestPointAvailable();
};


#endif //ARGENTUM_TALLER_NESTPOINTCONTAINER_H
