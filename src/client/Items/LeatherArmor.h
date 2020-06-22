#ifndef LEATHERARMOR_H
#define LEATHERARMOR_H

#include "Body.h"
#include "../TextureManager.h"

class LeatherArmor: public Body {
public:
    LeatherArmor(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~LeatherArmor();

};

#endif