#ifndef PLATEARMOR_H
#define PLATEARMOR_H

#include "Body.h"
#include "../TextureManager.h"

class PlateArmor: public Body {
private:
    void setDirection(int direction);
public:
    PlateArmor(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~PlateArmor();

};

#endif