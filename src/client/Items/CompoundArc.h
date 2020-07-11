#ifndef COMPOUNDARC_H
#define COMPOUNDARC_H

#include "Weapon.h"
#include "../TextureManager.h"

class CompoundArc: public Weapon {
private:
    void setDirection(int direction);
public:
    CompoundArc(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~CompoundArc();

};

#endif
