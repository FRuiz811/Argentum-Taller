#ifndef REDCOMMONBODY_H
#define REDCOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class RedCommonBody: public Body {
public:
    RedCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~RedCommonBody();

};

#endif