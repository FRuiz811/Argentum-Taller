#ifndef BODY_H
#define BODY_H

#include "Item.h"
#include "../Texture.h"
#include "../../common/Identificators.h"

class Body: public Item {
protected:
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{30.0};
    int totalFrames{5};
    BodyID id{BodyID::Nothing};
    Direction direction{Direction::down};
public:
    Body(const Texture& texture, const int width, const int height, BodyID id = BodyID::Nothing);
    
    virtual void render(int posX, int posY) = 0;

    void update(double dt, Direction dir);

    void setAnimationSpeed(float speed);

    int getHeight() const;

    BodyID getId()const;

    ~Body();;
};

#endif