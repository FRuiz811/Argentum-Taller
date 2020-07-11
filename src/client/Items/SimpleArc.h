#ifndef SIMPLEARC_H
#define SIMPLEARC_H

#include "Weapon.h"
#include "../TextureManager.h"

class SimpleArc: public Weapon {
private:
    void setDirection(int direction);
public:
    SimpleArc(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~SimpleArc();

};

#endif
