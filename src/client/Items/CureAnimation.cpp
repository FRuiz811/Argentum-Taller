#include "CureAnimation.h"

#define WIDTHFRAME 113
#define HEIGHTFRAME 113
#define FRAMES 20

CureAnimation::CureAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::HealthEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void CureAnimation::render(int x, int y) {
    if (this->finish) 
        return;
    if(!this->effectPlayed) {
        this->effect.playEffect();
        this->effectPlayed = true;
    }
    int row = this->totalFrames/4;
    SDL_Rect src = {this->width*(this->frame % row),
                     this->height*int(floor(this->frame/row)), this->width, this->height};
	SDL_Rect dst = {x-int(this->width/2.5), y-int(this->height/3), this->width, this->height};
    this->texture.render(src, dst);
}

CureAnimation::~CureAnimation() {}