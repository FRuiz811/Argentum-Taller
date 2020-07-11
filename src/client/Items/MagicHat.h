#ifndef MAGICHAT_H
#define MAGICHAT_H

#include "Helmet.h"
#include "../TextureManager.h"

class MagicHat: public Helmet {
public:
    MagicHat(const TextureManager& manager);

    virtual void render(int posX, int posY);
    
    virtual void update(int dir);

    ~MagicHat();

};

#endif