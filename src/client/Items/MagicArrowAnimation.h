#ifndef MAGICARROWANIMATION_H
#define MAGICARROWANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class MagicArrowAnimation: public Animation {
public:
    MagicArrowAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~MagicArrowAnimation();

};

#endif
