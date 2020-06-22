#ifndef GREENCOMMONBODY_H
#define GREENCOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class GreenCommonBody: public Body {
public:
    GreenCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~GreenCommonBody();

};

#endif