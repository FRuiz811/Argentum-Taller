#ifndef GNARLEDSTICK_H
#define GNARLEDSTICK_H

#include "Weapon.h"
#include "../TextureManager.h"

class GnarledStick: public Weapon {
private:
    void setDirection(int direction);
public:
    GnarledStick(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~GnarledStick();

};

#endif
