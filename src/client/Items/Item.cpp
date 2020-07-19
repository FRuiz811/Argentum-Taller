#include "Item.h"

Item::Item(const Texture& texture, const int width, const int height) : 
    texture(texture), width(width), height(height) {}

void Item::render(int posX, int posY) {
        SDL_Rect srcItem = {0,0, this->width, this->height};
	    SDL_Rect dstItem = {posX, posY, this->width, this->height};
        this->texture.render(srcItem, dstItem);
}

Item::~Item() {}