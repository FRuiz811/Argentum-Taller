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

	void playEffect(int times = 0) const;

	~Effect();
};

#endif
