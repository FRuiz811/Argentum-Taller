#include "PriestHead.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 17

PriestHead::PriestHead(const TextureManager& manager) :
 Head(manager.getTexture(TextureID::PriestHead),WIDTH_HEAD,HEIGHT_HEAD,HeadID::Priest) {}

void PriestHead::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width * direction, this->height * 0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void PriestHead::update(int dir){
    this->direction = dir;
}

PriestHead::~PriestHead(){}