#include "MusicManager.h"
#include <utility>
#include "MusicID.h"
#include "../common/Identificators.h"

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
	std::string path(ROOT_DIR);
	createMusic(MusicID::BackGround, path + "/assets/sound/Musica Inicio.mp3");
	createEffect(MusicID::Eagle, path + "/assets/sound/Aguila.wav");
	createEffect(MusicID::Walk, path + "/assets/sound/Caminata.wav");
	createEffect(MusicID::Cure, path + "/assets/sound/Curar.wav");
	createEffect(MusicID::Sword, path + "/assets/sound/Espada.wav");
	createEffect(MusicID::Skeleton, path + "/assets/sound/Esqueleto.wav");
	createEffect(MusicID::Explotion, path + "/assets/sound/Explosion.wav");
	createEffect(MusicID::MagicArrow, path + "/assets/sound/Flecha Magica.wav");
	createEffect(MusicID::Arrow, path + "/assets/sound/Flecha.wav");
	createEffect(MusicID::Goblin, path + "/assets/sound/Goblin.wav");
	createEffect(MusicID::Ax, path + "/assets/sound/Hacha.wav");
	createEffect(MusicID::Hammer, path + "/assets/sound/Martillo.wav");
	createEffect(MusicID::Meditation, path + "/assets/sound/Meditar.wav");
	createEffect(MusicID::Misil, path + "/assets/sound/Misil.wav");
	createEffect(MusicID::Death, path + "/assets/sound/Muerte.wav");
	createEffect(MusicID::Wind, path + "/assets/sound/Viento.wav");
	createEffect(MusicID::Zombie, path + "/assets/sound/Zombie.wav");
	createEffect(MusicID::Wolf, path + "/assets/sound/Lobo.wav");
	createEffect(MusicID::Raven, path + "/assets/sound/Cuervo.wav");
	createEffect(MusicID::Heart, path + "/assets/sound/Latidos.wav");
	createEffect(MusicID::Merchant, path + "/assets/sound/Comerciante.wav");
	createEffect(MusicID::Banker, path + "/assets/sound/Banquero.wav");
	createEffect(MusicID::Priest, path + "/assets/sound/Sacerdote.wav");
}

MusicManager::~MusicManager() {}
