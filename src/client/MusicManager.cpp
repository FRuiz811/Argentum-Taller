#include "MusicManager.h"
#include <utility>
#include "MusicID.h"

MusicManager::MusicManager() : songs(),effects() {}


void MusicManager::createMusic(MusicID id, const std::string& path) {
	Music newSong(path);
	this->songs.insert(std::make_pair(id, std::move(newSong)));
}

void MusicManager::createEffect(MusicID id, const std::string& path) {
	Effect newEffect(path);
	this->effects.insert(std::make_pair(id, std::move(newEffect)));
}

void MusicManager::dropMusic(MusicID id) {
	this->songs.erase(id);
}

void MusicManager::dropEffect(MusicID id) {
	this->effects.erase(id);
}

const Music& MusicManager::getMusic(MusicID id) const {
	return this->songs.at(id);
}

const Effect& MusicManager::getEffect(MusicID id) const {
	return this->effects.at(id);
}

void MusicManager::loadSounds() {
	createMusic(MusicID::BackGround, "assets/sound/Musica Inicio.mp3");
	createEffect(MusicID::Eagle, "assets/sound/Aguila.wav");
	createEffect(MusicID::Walk, "assets/sound/Caminata.wav");
	createEffect(MusicID::Cure, "assets/sound/Curar.wav");
	createEffect(MusicID::Sword, "assets/sound/Espada.wav");
	createEffect(MusicID::Skeleton, "assets/sound/Esqueleto.wav");
	createEffect(MusicID::Explotion, "assets/sound/Explosion.wav");
	createEffect(MusicID::MagicArrow, "assets/sound/Flecha Magica.wav");
	createEffect(MusicID::Arrow, "assets/sound/Flecha.wav");
	createEffect(MusicID::Goblin, "assets/sound/Goblin.wav");
	createEffect(MusicID::Ax, "assets/sound/Hacha.wav");
	createEffect(MusicID::Hammer, "assets/sound/Martillo.wav");
	createEffect(MusicID::Meditation, "assets/sound/Meditar.wav");
	createEffect(MusicID::Misil, "assets/sound/Misil.wav");
	createEffect(MusicID::Death, "assets/sound/Muerte.wav");
	createEffect(MusicID::Wind, "assets/sound/Viento.wav");
	createEffect(MusicID::Zombie, "assets/sound/Zombie.wav");
	createEffect(MusicID::Wolf, "assets/sound/Lobo.wav");
	createEffect(MusicID::Raven, "assets/sound/Cuervo.wav");
	createEffect(MusicID::Heart, "assets/sound/Latidos.wav");

}

MusicManager::~MusicManager() {}
