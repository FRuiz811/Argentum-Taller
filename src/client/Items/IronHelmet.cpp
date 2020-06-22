#include "IronHelmet.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

IronHelmet::IronHelmet(const TextureManager& manager) :
 Helmet(manager.getTexture(TextureID::IronHelmet),WIDTH_HEAD,HEIGHT_HEAD) {}

void IronHelmet::render(int posX, int posY, int direction) {
    SDL_Rect srcHead = {this->width*direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

IronHelmet::~IronHelmet(){}