#ifndef SKELETONBODY_H
#define SKELETONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class SkeletonBody: public Body {
private:
    void setDirection(int direction);
public:
    SkeletonBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~SkeletonBody();

};

#endif