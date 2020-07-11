#ifndef GREENCOMMONBODY_H
#define GREENCOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class GreenCommonBody: public Body {
private:
    void setDirection(int direction);
public:
    GreenCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~GreenCommonBody();

};

#endif
