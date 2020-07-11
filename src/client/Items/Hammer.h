#ifndef HAMMER_H
#define HAMMER_H

#include "Weapon.h"
#include "../TextureManager.h"

class Hammer: public Weapon {
private:
    void setDirection(int direction);
public:
    Hammer(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~Hammer();

};

#endif
