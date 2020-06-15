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
	Music(Music&& other);

	int playMusic(int times) const ;

	void pauseMusic() const;

	void stopMusic() const;

	~Music();
};

#endif
