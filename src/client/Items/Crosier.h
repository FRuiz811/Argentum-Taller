#ifndef CROSIER_H
#define CROSIER_H

#include "Weapon.h"
#include "../TextureManager.h"

class Crosier: public Weapon {
private:
    void setDirection(int direction);
public:
    Crosier(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~Crosier();

};

#endif
