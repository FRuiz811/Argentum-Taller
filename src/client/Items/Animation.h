#ifndef ANIMATION_H
#define ANIMATION_H

#include "../Effect.h"
#include "../Texture.h"

class Animation {
protected:
    const Effect& effect;
    const Texture& texture;
    const int width; //Ancho del Frame
    const int height; //Alto del Frame
    int totalFrames{0};
    int frame{0};
    float elapsed{0.0};
    float animationSpeed{45.0f};
    bool finish{false};
    bool effectPlayed{false};
public:
    Animation(const Texture& texture, const int width, const int height, const Effect& effect,int totalFrames) :
    effect(effect), texture(texture), width(width), height(height), totalFrames(totalFrames) {}

    virtual void render(int x, int y) = 0;

    void update() {
        this->frame ++;
        if (this->frame >= this->totalFrames)
            this->finish = true;
        this->frame = this->frame % this->totalFrames;
    }

    bool finished() const {
        return this->finish;
    }

    ~Animation() {}

};

#endif