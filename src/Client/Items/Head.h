#ifndef HEAD_H
#define HEAD_H

#include "Item.h"
#include "../Texture.h"

class Head: public Item {
public:
    Head(const Texture& texture, const int width, const int height) : 
        Item(texture, width, height){}
    
    virtual void render(int posX, int posY, int direction) = 0;

    ~Head() {};
};

#endif