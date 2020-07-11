#ifndef ASHSTICK_H
#define ASHSTICK_H

#include "Weapon.h"
#include "../TextureManager.h"

class AshStick: public Weapon {
private:
    void setDirection(int direction);
public:
    AshStick(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~AshStick();

};

#endif
