#include "MagicArrowAnimation.h"

#define WIDTHFRAME 62
#define HEIGHTFRAME 60
#define FRAMES 5

MagicArrowAnimation::MagicArrowAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::MagicArrowEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void MagicArrowAnimation::render(int x, int y) {
    if (this->finish) 
        return;
    if(!this->effectPlayed) {
        this->effect.playEffect();
        this->effectPlayed = true;
    }
    SDL_Rect src = {this->width*this->frame, this->height*0, this->width, this->height};
	SDL_Rect dst = {x, y, this->width, this->height};
    this->texture.render(src, dst);
}

MagicArrowAnimation::~MagicArrowAnimation() {}