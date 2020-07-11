#ifndef HUMANHEAD_H
#define HUMANHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class HumanHead: public Head {
public:
    HumanHead(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(int dir);

    ~HumanHead();

};

#endif