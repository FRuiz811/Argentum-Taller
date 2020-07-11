#ifndef REDCOMMONBODY_H
#define REDCOMMONBODY_H

#include "Body.h"
#include "../TextureManager.h"

class RedCommonBody: public Body {
private:
    void setDirection(int direction);
public:
    RedCommonBody(const TextureManager& manager);

    virtual void render(int posX, int posY);

    virtual void update(double dt,Direction dir);

    ~RedCommonBody();

};

#endif