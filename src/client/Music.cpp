#include "Music.h"
#include <SDL2/SDL_mixer.h>
#include "../common/Exception.h"


Music::Music(const std::string& fileName) : reproduce(false) {
	this->music = loadMusic(fileName);
}

int Music::playMusic(int times) const {
	return Mix_PlayMusic(this->music, times);
}

Music::Music(Music &&other) {
    std::swap(this->music, other.music);
}


Mix_Music* Music::loadMusic(const std::string &fileName) {
	if (!this->music) {
		this->music = Mix_LoadMUS(fileName.c_str());
	}
	if (!this->music){
		throw Exception("Fail loading music: %s",Mix_GetError());
	}
	return this->music;
}

void Music::setVolume(int volume) const{
	Mix_VolumeMusic(volume);
}

void Music::pauseMusic() const {
	if (Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
	else 
		Mix_PauseMusic();
}

void Music::stopMusic() const {
	Mix_HaltMusic();
}

Music::~Music() {
	if (this->music) {
		Mix_FreeMusic(this->music);
		this->music = nullptr;
	}
}
