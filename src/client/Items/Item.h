#ifndef ITEM_H
#define ITEM_H

#include "../Texture.h"

class Item {
protected:
    const Texture& texture;
    const int width; //Ancho del Frame
    const int height; //Alto del Frame
public:
    Item(const Texture& texture, const int width, const int height) : texture(texture),
        width(width), height(height) {}

    virtual void render(int posX, int posY) {
        SDL_Rect srcItem = {0,0, this->width, this->height};
	    SDL_Rect dstItem = {posX, posY, this->width, this->height};
        this->texture.render(srcItem, dstItem);
    }
    
    ~Item()= default;
};

#endif 