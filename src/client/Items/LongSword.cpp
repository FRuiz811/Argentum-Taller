#include "LongSword.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

LongSword::LongSword(const TextureManager& manager):
    Weapon(manager.getTexture(TextureID::LongSword),WIDTH_BODY,HEIGHT_BODY, WeaponID::LongSword) {}

void LongSword::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstHead = {posX, posY, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void LongSword::update(double dt,Direction dir) {
    setDirection(int(dir));
    Weapon::update(dt,dir);
}

void LongSword::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


LongSword::~LongSword(){}
