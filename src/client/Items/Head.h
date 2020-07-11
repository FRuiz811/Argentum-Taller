#ifndef HEAD_H
#define HEAD_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Head: public Item {
protected:
    HeadID id{HeadID::Nothing};
    int direction{0};
public:
    Head(const Texture& texture, const int width, const int height,HeadID id = HeadID::Nothing) : 
        Item(texture, width, height), id(id){}
    
    virtual void render(int posX, int posY) = 0;

    virtual void update(int dir) = 0;

    HeadID getId(){
        return this->id;
    }

    ~Head() {};
};

#endif