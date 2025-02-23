#ifndef TURTLESHIELD_H
#define TURTLESHIELD_H

#include "Shield.h"
#include "../TextureManager.h"

class TurtleShield: public Shield {
private:
    void setDirection(int direction);
public:
    TurtleShield(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~TurtleShield();

};

#endif