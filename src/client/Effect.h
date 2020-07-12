#ifndef EFFECT_H
#define EFFECT_H

#include <SDL2/SDL_mixer.h>
#include <string>

class Effect {
private:
	Mix_Chunk* effect = nullptr;
    mutable int channel;
public:
	explicit Effect(const std::string &fileName);

	Effect(Effect&& other);

	void playEffect(int times = 0,int volume=-1) const;

	void setDistance(int distance) const;

	void pause() const;

	~Effect();
};

#endif
