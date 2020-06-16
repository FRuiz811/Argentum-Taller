#include "Animation.h"
#include <SDL2/SDL.h>

Animation::Animation(const Texture& texture, int widthSprite, int heightSprite, int speed)
    : texture(texture), widthSprite(widthSprite), heightSprite(heightSprite),
    animationSpeed(speed){

    }

void Animation::update(double dt) {
    this->frameCount = (SDL_GetTicks()/this->animationSpeed) % this->totalFrames;
}

void Animation::render(int row, int totalFrames) {
    
}