#include "HumanHead.h"
#include "../TextureID.h"

#define WIDTH_HEAD 17
#define HEIGHT_HEAD 16

HumanHead::HumanHead(const TextureManager& manager) :
 Head(manager.getTexture(TextureID::HumanHead),WIDTH_HEAD,HEIGHT_HEAD,HeadID::Human) {}

void HumanHead::render(int posX, int posY) {
    SDL_Rect srcHead = {this->width*this->direction, this->height*0, this->width, this->height};
	SDL_Rect dstHead = {posX, posY+this->height-2, this->width, this->height};
    this->texture.render(srcHead, dstHead);
}

void HumanHead::update(int dir){
    this->direction = dir;
}


HumanHead::~HumanHead(){}