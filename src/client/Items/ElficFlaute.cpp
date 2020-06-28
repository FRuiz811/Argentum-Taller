#include "ElficFlaute.h"
#include "../TextureID.h"

#define WIDTH_BODY 42
#define HEIGHT_BODY 64

ElficFlaute::ElficFlaute(const TextureManager& manager):
    Weapon(manager.getTexture(TextureID::ElficFlaute),WIDTH_BODY,HEIGHT_BODY, WeaponID::ElficFlaute) {}

void ElficFlaute::render(int posX, int posY, int direction) {
    setDirection(direction);
    SDL_Rect srcHead = {this->width*frame, this->height*direction, this->width, this->height};
	SDL_Rect dstHead = {posX-5, posY-5-this->height/4, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void ElficFlaute::update(double dt) {
    Weapon::update(dt);
}

void ElficFlaute::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


ElficFlaute::~ElficFlaute(){}
