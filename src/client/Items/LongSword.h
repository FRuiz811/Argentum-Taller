#ifndef LONGSWORD_H
#define LONGSWORD_H

#include "Weapon.h"
#include "../TextureManager.h"

class LongSword: public Weapon {
private:
    void setDirection(int direction);
public:
    LongSword(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);
    
    ~LongSword();

};

#endif
