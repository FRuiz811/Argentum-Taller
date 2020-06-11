#include "SDLMusic.h"
#include <SDL2/SDL_mixer.h>
#include "SDLException.h"

#define CHANNELS 2
#define MIX_CHUNKSIZE 1024

SDLMusic::SDLMusic(const std::string& fileName) : reproduce(false) {
		if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 
									CHANNELS, MIX_CHUNKSIZE) == -1) {
			throw SDLException("Fail Mix_OpenAudio: %s", Mix_GetError());
		}

		this->music = loadMusic(fileName);
}

int SDLMusic::playMusic(int times) {
	this->reproduce =true;
	return Mix_PlayMusic(this->music, times);
}

Mix_Music* SDLMusic::loadMusic(const std::string &fileName) {
	if (!this->music) {
		this->music = Mix_LoadMUS(fileName.c_str());
	}
	if (!this->music){
		throw SDLException("Fail loading music: %s",Mix_GetError());
	}
	return this->music;
}

bool SDLMusic::isPlaying() const {
	return this->reproduce;
}

void SDLMusic::pauseMusic() {
	this->reproduce = false;
	Mix_PauseMusic();
}

SDLMusic::~SDLMusic() {
	Mix_CloseAudio();
	if (!this->music)
		Mix_FreeMusic(this->music);
}
