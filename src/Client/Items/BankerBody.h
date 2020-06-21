#ifndef BANKERBODY_H
#define BANKERBODY_H

#include "Body.h"
#include "../TextureManager.h"

class BankerBody: public Body {
private:
    void setDirection(int direction);
public:
    BankerBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~BankerBody();

};

#endif