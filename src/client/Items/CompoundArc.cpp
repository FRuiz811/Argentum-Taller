#include "CompoundArc.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

CompoundArc::CompoundArc(const TextureManager& manager):
    Weapon(manager.getTexture(TextureID::CompoundArc),WIDTH_BODY,HEIGHT_BODY, WeaponID::CompoundArc) {}

void CompoundArc::render(int posX, int posY) {
    SDL_Rect srcWeapon = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstWeapon = {posX, posY, this->width, this->height};
    this->texture.render(srcWeapon, dstWeapon);
}

void CompoundArc::update(double dt,Direction dir) {
    setDirection(int(dir));
    Weapon::update(dt,dir);
}

void CompoundArc::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


CompoundArc::~CompoundArc(){}
