#ifndef PRIESTBODY_H
#define PRIESTBODY_H

#include "Body.h"
#include "../TextureManager.h"

class PriestBody: public Body {
private:
    void setDirection(int direction);
public:
    PriestBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~PriestBody();

};

#endif