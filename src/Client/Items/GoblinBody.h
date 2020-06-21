#ifndef GOBLINBODY_h
#define GOBLINBODY_h

#include "Body.h"
#include "../TextureManager.h"

class GoblinBody: public Body {
private:
    void setDirection(int direction);
public:
    GoblinBody(const TextureManager& manager);

    virtual void render(int posX, int posY, int direction);

    virtual void update(double dt);

    ~GoblinBody();

};

#endif