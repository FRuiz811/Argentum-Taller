#ifndef HEAD_H
#define HEAD_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Head: public Item {
    HeadID id{HeadID::Nothing};
public:
    Head(const Texture& texture, const int width, const int height,HeadID id = HeadID::Nothing) : 
        Item(texture, width, height){}
    
    virtual void render(int posX, int posY, int direction) = 0;

    HeadID getId(){
        return this->id;
    }

    ~Head() {};
};

#endif