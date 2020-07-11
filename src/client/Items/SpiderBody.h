#ifndef SPIDERBODY_H
#define SPIDERBODY_H

#include "Body.h"
#include "../TextureManager.h"

class SpiderBody: public Body {
public:
    SpiderBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~SpiderBody();

};

#endif