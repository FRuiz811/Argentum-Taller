#ifndef HOOD_H
#define HOOD_H

#include "Helmet.h"
#include "../TextureManager.h"

class Hood: public Helmet {
public:
    Hood(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    ~Hood();

};

#endif