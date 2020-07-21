#include "Animation.h"

Animation::Animation(const Texture& texture, const int width, const int height, 
    const Effect& effect,int totalFrames) : effect(effect), texture(texture),
    width(width), height(height), totalFrames(totalFrames) {}

void Animation::update() {
        this->frame ++;
        if (this->frame >= this->totalFrames)
            this->finish = true;
        this->frame = this->frame % this->totalFrames;
}

bool Animation::finished() const {
        return this->finish;
}

Animation::~Animation() {}