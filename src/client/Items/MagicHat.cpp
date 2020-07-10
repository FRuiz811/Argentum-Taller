#include "MagicHat.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

MagicHat::MagicHat(const TextureManager& manager) :
 Helmet(manager.getTexture(TextureID::MagicHat),WIDTH_HEAD,HEIGHT_HEAD,HelmetID::MagicHat) {}

void MagicHat::render(int posX, int posY, int direction) {
    SDL_Rect srcHead = {this->width*direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY-this->height/4+4, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

MagicHat::~MagicHat(){}