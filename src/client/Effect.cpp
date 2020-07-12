#include "Effect.h"
#include "../common/Exception.h"
#include <iostream>

Effect::Effect(const std::string& fileName) {
	this->effect = Mix_LoadWAV(fileName.c_str());
	if(this->effect == NULL) {
		std::cout << "ERROR al cargar el archivo" << fileName << std::endl;
	}
    this->channel = -1;
}

void Effect::playEffect(int times,int volume) const {
	Mix_VolumeChunk(this->effect,volume);
	this->channel = Mix_PlayChannel(-1,this->effect,times);
}

void Effect::pause() const {
	Mix_Pause(this->channel);
}

Effect::Effect(Effect &&other) {
    std::swap(this->effect, other.effect);
    std::swap(this->channel,other.channel);
}

void Effect::setDistance(int distance) const {
	Mix_SetDistance(this->channel,distance);
}

Effect::~Effect() {
	if (this->effect) {
		Mix_FreeChunk(this->effect);
		this->effect = nullptr;
	}
}
