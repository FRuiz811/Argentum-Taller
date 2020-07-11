#ifndef AX_H
#define AX_H

#include "Weapon.h"
#include "../TextureManager.h"

class Ax: public Weapon {
private:
    void setDirection(int direction);
public:
    Ax(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~Ax();

};

#endif
