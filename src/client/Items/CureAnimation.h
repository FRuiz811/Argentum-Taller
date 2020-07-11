#ifndef CUREANIMATION_H
#define CUREANIMATION_H

#include "Animation.h"
#include "../TextureManager.h"
#include "../Effect.h"

class CureAnimation: public Animation {
public:
    CureAnimation(const TextureManager& manager,const Effect& effect);

    virtual void render(int x, int y);

    ~CureAnimation();

};

#endif