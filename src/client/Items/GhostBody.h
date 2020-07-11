#ifndef GHOSTBODY_H
#define GHOSTBODY_H

#include "Body.h"
#include "../TextureManager.h"

class GhostBody: public Body {
private:
    void setDirection(int direction);
public:
    GhostBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~GhostBody();

};

#endif