#ifndef BLUECOMMONBODY_H
#define BLUECOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class BlueCommonBody: public Body {
private:
    void setDirection(int direction);
public:
    BlueCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~BlueCommonBody();

};

#endif