#ifndef IRONSHIELD_H
#define IRONSHIELD_H

#include "Shield.h"
#include "../TextureManager.h"

class IronShield: public Shield {
private:
    void setDirection(int direction);
public:
    IronShield(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~IronShield();

};

#endif