#include "HitAnimation.h"
#include "../../common/Random.h"
#define WIDTHFRAME 15
#define HEIGHTFRAME 15
#define FRAMES 10

HitAnimation::HitAnimation(const TextureManager& manager,const Effect& effect) :
 Animation(manager.getTexture(TextureID::HitEffect),WIDTHFRAME, HEIGHTFRAME,effect,FRAMES) {}

void HitAnimation::render(int x, int y) {
    if (this->finish) 
        return;
    if(!this->effectPlayed) {
        this->effect.playEffect();
        this->effectPlayed = true;
    }
    int randX = Random::get(0,this->width);
    int randY = Random::get(0,this->height*2);
    SDL_Rect src = {this->width*this->frame, this->height*0, this->width, this->height};
	SDL_Rect dst = {x+randX, y+randY, this->width, this->height};
    this->texture.render(src, dst);
}

HitAnimation::~HitAnimation() {}