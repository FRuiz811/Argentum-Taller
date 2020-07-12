#include "ExplotionAnimation.h"

#define WIDTHFRAME 62
#define HEIGHTFRAME 60
#define FRAMES 10

ExplotionAnimation::ExplotionAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::ExplotionEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void ExplotionAnimation::render(int x, int y) {
    if (this->finish) 
        return;
    if(!this->effectPlayed) {
        this->effect.playEffect(0,64);
        this->effectPlayed = true;
    }
    int row = this->totalFrames/2;
    SDL_Rect src = {this->width*(this->frame % row),
                     this->height*int(floor(this->frame/row)), this->width, this->height};
	SDL_Rect dst = {x-int(this->width/3), y-int(this->height/3), this->width, this->height};
    this->texture.render(src, dst);
}

ExplotionAnimation::~ExplotionAnimation() {}