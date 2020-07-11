#ifndef GNOMEHEAD_H
#define GNOMEHEAD_H

#include "Head.h"
#include "../TextureManager.h"

class GnomeHead: public Head {
public:
    GnomeHead(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(int dir);

    ~GnomeHead();

};

#endif