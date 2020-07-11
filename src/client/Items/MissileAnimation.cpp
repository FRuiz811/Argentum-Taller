#include "MissileAnimation.h"

#define WIDTHFRAME 85
#define HEIGHTFRAME 70
#define FRAMES 7

MissileAnimation::MissileAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::MissileEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void MissileAnimation::render(int x, int y) {
    if (this->finish) 
        return;
    if(!this->effectPlayed) {
        this->effect.playEffect();
        this->effectPlayed = true;
    }
    SDL_Rect src = {this->width*this->frame,this->height*0, this->width, this->height};
	SDL_Rect dst = {x, y, this->width, this->height};
    this->texture.render(src, dst);
}

MissileAnimation::~MissileAnimation() {}