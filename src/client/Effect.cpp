#include "Effect.h"
#include "../common/Exception.h"


Effect::Effect(const std::string& fileName) {
	this->effect = Mix_LoadWAV(fileName.c_str());
    this->channel = -1;
}

void Effect::playEffect(int times) const {
	if(!Mix_Playing(this->channel))
        this->channel = Mix_PlayChannel(-1,this->effect,times);
}

Effect::Effect(Effect &&other) {
    std::swap(this->effect, other.effect);
    std::swap(this->channel,other.channel);
}

Effect::~Effect() {
	if (this->effect) {
		Mix_FreeChunk(this->effect);
		this->effect = nullptr;
	}
}
