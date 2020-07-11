#include "MagicHat.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

MagicHat::MagicHat(const TextureManager& manager) :
 Helmet(manager.getTexture(TextureID::MagicHat),WIDTH_HEAD,HEIGHT_HEAD,HelmetID::MagicHat) {}

void MagicHat::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*this->direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY-this->height/4+4, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void MagicHat::update(int dir) {
    this->direction = dir;
}

MagicHat::~MagicHat(){}