#ifndef MUSIC_H
#define MUSIC_H
#include <string>

typedef struct _Mix_Music Mix_Music;

class Music {
private:
	Mix_Music* music = nullptr;
	bool reproduce;
	Mix_Music* loadMusic(const std::string &fileName);

public:
	explicit Music(const std::string &fileName);

	int playMusic(int times);

	void pauseMusic();

	void stopMusic();

	~Music();
};

#endif
