#include "MusicManager.h"
#include <utility>

MusicManager::MusicManager() : songs() {}


void MusicManager::createMusic(MusicID id, const std::string& path) {
	Music newSong(path);
	this->songs.insert(std::make_pair(id, std::move(newSong)));
}

void MusicManager::dropMusic(MusicID id) {
	this->songs.erase(id);
}

const Music& MusicManager::getMusic(MusicID id) const {
	return this->songs.at(id);
}

MusicManager::~MusicManager() {}
