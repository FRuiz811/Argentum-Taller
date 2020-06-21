#ifndef ELFHEAD_H
#define ELFHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class ElfHead: public Head {
public:
    ElfHead(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    ~ElfHead();

};

#endif