#ifndef MAGICHAT_H
#define MAGICHAT_H

#include "Helmet.h"
#include "../TextureManager.h"

class MagicHat: public Helmet {
public:
    MagicHat(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    ~MagicHat();

};

#endif