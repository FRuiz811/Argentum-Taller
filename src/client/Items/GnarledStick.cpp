#include "GnarledStick.h"
#include "../TextureID.h"

#define WIDTH_BODY 25
#define HEIGHT_BODY 45

GnarledStick::GnarledStick(const TextureManager& manager):
    Weapon(manager.getTexture(TextureID::GnarledStick),WIDTH_BODY,HEIGHT_BODY, WeaponID::GnarledStick) {}

void GnarledStick::render(int posX, int posY) {
    SDL_Rect srcWeapon = {this->width*frame, this->height*int(direction), this->width, this->height};
	SDL_Rect dstWeapon = {posX, posY-2, this->width, this->height};
    this->texture.render(srcWeapon, dstWeapon);
}

void GnarledStick::update(double dt,Direction dir) {
    setDirection(int(dir));
    Weapon::update(dt,dir);
}

void GnarledStick::setDirection(int direction) {
    if (direction == 0 || direction == 1)
        this->totalFrames = 6;
    if (direction == 2|| direction == 3)
        this->totalFrames = 5;   
}


GnarledStick::~GnarledStick(){}
