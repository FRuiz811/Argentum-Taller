#ifndef HITANIMATION_H
#define HITANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class HitAnimation: public Animation {
public:
    HitAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~HitAnimation();

};

#endif
