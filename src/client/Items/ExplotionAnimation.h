#ifndef EXPLOTIONANIMATION_H
#define EXPLOTIONANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class ExplotionAnimation: public Animation {
public:
    ExplotionAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~ExplotionAnimation();

};

#endif