#ifndef SDLMusic_H
#define SDLMusic_H
#include <string>

typedef struct _Mix_Music Mix_Music;

class SDLMusic {
private:
	Mix_Music* music = nullptr;
	bool reproduce;
	Mix_Music* loadMusic(const std::string &fileName);

public:
	explicit SDLMusic(const std::string &fileName);

	int playMusic(int times);

	void pauseMusic();

	bool isPlaying() const;

	~SDLMusic();
};

#endif
