#ifndef MERCHANTBODY_H
#define MERCHANTBODY_H

#include "Body.h"
#include "../TextureManager.h"

class MerchantBody: public Body {
private:
    void setDirection(int direction);
public:
    MerchantBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~MerchantBody();

};

#endif