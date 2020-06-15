#ifndef ANIMATION_H
#define ANIMATION_H
#include "Texture.h"

class Animation {
private:
    const Texture& texture;
    int widthSprite, heightSprite;
    int animationSpeed, frameCount, totalFrames;
public:
    Animation(const Texture& texture, int widthSprite, int heightSprite, int speed);
    void update(double dt);
    void render(int row, int totalFrames);



};

#endif
