#ifndef AX_H
#define AX_H

#include "Weapon.h"
#include "../TextureManager.h"

class Ax: public Weapon {
private:
    void setDirection(int direction);
public:
    Ax(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~Ax();

};

#endif
