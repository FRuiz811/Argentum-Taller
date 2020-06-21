#ifndef BLUETONIC_H
#define BLUETONIC_H

#include "Body.h"
#include "../TextureManager.h"

class BlueTunic: public Body {
public:
    BlueTunic(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~BlueTunic();

};

#endif