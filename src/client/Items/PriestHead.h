#ifndef PRIESTHEAD_H
#define PRIESTHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class PriestHead: public Head {
public:
    PriestHead(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(int dir);

    ~PriestHead();

};

#endif