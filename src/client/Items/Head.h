#ifndef HEAD_H
#define HEAD_H

#include "Item.h"
#include "../Texture.h"
#include "../characterStates/CharacterStatesID.h"

class Head: public Item {
    HeadID id{HeadID::Other};
public:
    Head(const Texture& texture, const int width, const int height,HeadID id = HeadID::Other) : 
        Item(texture, width, height){}
    
    virtual void render(int posX, int posY, int direction) = 0;

    HeadID getId(){
        return this->id;
    }

    ~Head() {};
};

#endif