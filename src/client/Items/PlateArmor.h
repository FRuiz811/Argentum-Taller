#ifndef PLATEARMOR_H
#define PLATEARMOR_H

#include "Body.h"
#include "../TextureManager.h"

class PlateArmor: public Body {
public:
    PlateArmor(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt, int animationSpeed, int totalFrames);

    ~PlateArmor();

};

#endif