#include "MeditateAnimation.h"

#define WIDTHFRAME 80
#define HEIGHTFRAME 170
#define FRAMES 10

MeditateAnimation::MeditateAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::MeditateEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void MeditateAnimation::render(int x, int y) {
    if(!this->effectPlayed) {
        this->effect.playEffect(0,64);
        this->effectPlayed = true;
    }
    int row = this->totalFrames/2;
    SDL_Rect src = {this->width*(this->frame % row),
                     this->height*int(floor(this->frame/row)), this->width, this->height};
	SDL_Rect dst = {x-int(this->width/3), y-int(this->height/1.5), this->width, this->height};
    this->texture.render(src, dst);
    this->finish=false;
}

MeditateAnimation::~MeditateAnimation() {}