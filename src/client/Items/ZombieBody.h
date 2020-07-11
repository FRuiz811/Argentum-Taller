#ifndef ZOMBIEBODY_H
#define ZOMBIEBODY_H

#include "Body.h"
#include "../TextureManager.h"

class ZombieBody: public Body {
private:
    void setDirection(int direction);
public:
    ZombieBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~ZombieBody();

};

#endif