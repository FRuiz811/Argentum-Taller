#ifndef HELMET_H
#define HELMET_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Helmet: public Item {
protected:
    HelmetID id{HelmetID::Nothing};
    int direction{0};
public:
    Helmet(const Texture& texture, const int width, const int height,HelmetID id=HelmetID::Nothing) : 
        Item(texture, width, height),id(id){}
    
    virtual void render(int posX, int posY) = 0;

    virtual void update(int dir) = 0;

    HelmetID getId(){
        return this->id;
    }
    
    ~Helmet() {};
};

#endif