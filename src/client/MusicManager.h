#ifndef MUSICMANAGER_H
#define MUSICMANAGER_H
#include "Music.h"
#include "MusicID.h"
#include <unordered_map>
#include <string>

class MusicManager {
private:
	std::unordered_map<MusicID, Music, std::hash<MusicID>> songs;

public:
	MusicManager();

	void createMusic(MusicID id, const std::string& path);

	void dropMusic(MusicID id);

	const Music& getMusic(MusicID id) const;

	~MusicManager();

	MusicManager(const MusicManager&) = delete;
    MusicManager &operator=(const MusicManager&) = delete;
};

#endif
