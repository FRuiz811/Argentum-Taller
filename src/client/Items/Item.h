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

    virtual void render(int posX, int posY,int direction) = 0;
    ~Item()= default;
};

#endif 