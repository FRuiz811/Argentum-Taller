#include "ElficFlaute.h"
#include "../TextureID.h"

#define WIDTH_BODY 42
#define HEIGHT_BODY 64

ElficFlaute::ElficFlaute(const TextureManager& manager):
    Weapon(manager.getTexture(TextureID::ElficFlaute),WIDTH_BODY,HEIGHT_BODY, WeaponID::ElficFlaute) {}

void ElficFlaute::render(int posX, int posY) {
    SDL_Rect srcWeapon = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstWeapon = {posX, posY, this->width, this->height};
    this->texture.render(srcWeapon, dstWeapon);
}

void ElficFlaute::update(double dt,Direction dir) {
    setDirection(int(dir));
    Weapon::update(dt,dir);
}

void ElficFlaute::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


ElficFlaute::~ElficFlaute(){}
