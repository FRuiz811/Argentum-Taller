#ifndef ZOMBIEHEAD_H
#define ZOMBIEHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class ZombieHead: public Head {
public:
    ZombieHead(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    ~ZombieHead();

};

#endif