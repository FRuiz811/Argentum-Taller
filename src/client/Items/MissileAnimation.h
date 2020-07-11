#ifndef MISSILEANIMATION_H
#define MISSILEANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class MissileAnimation: public Animation {
public:
    MissileAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~MissileAnimation();

};

#endif
