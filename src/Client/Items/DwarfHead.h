#ifndef DWARFHEAD_H
#define DWARFHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class DwarfHead: public Head {
public:
    DwarfHead(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    ~DwarfHead();

};

#endif