#ifndef ARGENTUM_TALLER_NESTCONTAINER_H
#define ARGENTUM_TALLER_NESTCONTAINER_H


#include <vector>
#include "Nest.h"

class NestContainer {
private:
    std::vector<Nest> nests;
    uint8_t pos = 0;
    uint8_t length{};
public:
    NestContainer();

    explicit NestContainer(std::vector<Nest> nest);

    virtual ~NestContainer();

    Nest& getNextNestAvailable();

    std::vector<Nest> &getNests();

    int getAmountCreatures();

    Nest &getNest(uint i);
};


#endif //ARGENTUM_TALLER_NESTCONTAINER_H
