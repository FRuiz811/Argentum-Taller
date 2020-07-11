#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H
#include "Music.h"
#include "Effect.h"
#include "MusicID.h"
#include <unordered_map>
#include <string>

class MusicManager {
private:
	std::unordered_map<MusicID, Music, std::hash<MusicID>> songs;
	std::unordered_map<MusicID, Effect, std::hash<MusicID>> effects;

	void createMusic(MusicID id, const std::string& path);
	void createEffect(MusicID id, const std::string& path);
public:
	MusicManager();

	void dropMusic(MusicID id);
	void dropEffect(MusicID id);
	
	const Music& getMusic(MusicID id) const;

	const Effect& getEffect(MusicID id) const ;

	void loadSounds();

	~MusicManager();

	MusicManager(const MusicManager&) = delete;
    MusicManager &operator=(const MusicManager&) = delete;
};

#endif
