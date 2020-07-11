#ifndef MEDITATEANIMATION_H
#define MEDITATEANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class MeditateAnimation: public Animation {
public:
    MeditateAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~MeditateAnimation();

};

#endif