#ifndef IRONHELMET_H
#define IRONHELMET_H

#include "Helmet.h"
#include "../TextureManager.h"

class IronHelmet: public Helmet {
public:
    IronHelmet(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(int dir);
    
    ~IronHelmet();

};

#endif