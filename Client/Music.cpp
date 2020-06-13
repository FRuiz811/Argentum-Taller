#include "Music.h"
#include <SDL2/SDL_mixer.h>
#include "Exception.h"


Music::Music(const std::string& fileName) : reproduce(false) {
	this->music = loadMusic(fileName);
}

int Music::playMusic(int times) {
	this->reproduce =true;
	return Mix_PlayMusic(this->music, times);
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

void Music::pauseMusic() {
	if (this->reproduce == true)
		Mix_PauseMusic();
	else 
		Mix_ResumeMusic();
}

void Music::stopMusic() {
	Mix_HaltMusic();
}

Music::~Music() {
	if (!this->music)
		Mix_FreeMusic(this->music);
}
