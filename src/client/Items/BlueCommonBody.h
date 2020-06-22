#ifndef BLUECOMMONBODY_H
#define BLUECOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class BlueCommonBody: public Body {
public:
    BlueCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~BlueCommonBody();

};

#endif