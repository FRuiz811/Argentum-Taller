#include "MusicManager.h"
#include <utility>

MusicManager::MusicManager() : songs() {}


void MusicManager::createMusic(MusicID id, std::string path) {
	Music newSong(path);
	this->songs.insert(std::make_pair(id, std::move(newSong)));
}

void MusicManager::dropMusic(MusicID id) {
	this->songs.erase(id);
}

Music& MusicManager::getMusic(MusicID id) {
	return this->songs.at(id);
}

MusicManager::~MusicManager() {
	this->songs.clear();
}
