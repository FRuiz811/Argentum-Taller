#ifndef BLUETONIC_H
#define BLUETONIC_H

#include "Body.h"
#include "../TextureManager.h"

class BlueTunic: public Body {
private:
    void setDirection(int direction);
public:
    BlueTunic(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~BlueTunic();

};

#endif