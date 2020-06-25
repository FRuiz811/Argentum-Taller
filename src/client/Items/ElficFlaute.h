#ifndef ELFICFLAUTE_H
#define ELFICFLAUTE_H

#include "Weapon.h"
#include "../TextureManager.h"

class ElficFlaute: public Weapon {
private:
    void setDirection(int direction);
public:
    ElficFlaute(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~ElficFlaute();

};

#endif
