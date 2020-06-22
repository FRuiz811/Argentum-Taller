#include "SDL2/SDL.h"
#include <utility>
#include <unistd.h>
#include "Window.h"
#include "Chrono.h"
#include "Music.h"
#include "MusicManager.h"
#include "TextureManager.h"
#include "TextureID.h"
#include "MusicID.h"
#include "Presentation.h"
#include "Zombie.h"
#include "GameMap.h"
#include "Player.h"
#include "Spider.h"
#include "Camera.h"
#include "Point.h"
#include "Priest.h"


#define ARGENTUM "Argentum Online"
#define GAMELOOPTIME 50000

int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event event;

	Window window(ARGENTUM);
    ServerProxy serverProxy;
    GameMap gameMap(serverProxy.getStaticMap(), window.getRenderer());
    PlayerInfo playerInfo = serverProxy.createCharacter(0, 0);
	SDL_Color textColor = {0x0, 0x0, 0x0};

	TextureManager textureManager(window.getRenderer());
	textureManager.createTexture(TextureID::PresentationImage, "assets/img/ImagenPresentacion.jpg");
	textureManager.createTexture(TextureID::LobbyBackground, "assets/img/Fondo Inicio.jpg");
	textureManager.createTexture(TextureID::ZombieHead, "assets/img/Zombie Cabeza.png",textColor);
	textureManager.createTexture(TextureID::ElfHead,"assets/img/Cabeza Elfo.png", textColor);
	textureManager.createTexture(TextureID::HumanHead, "assets/img/Cabeza Humano.png",textColor);
	textureManager.createTexture(TextureID::DwarfHead, "assets/img/Cabeza Enano.png",textColor);
	textureManager.createTexture(TextureID::GnomeHead, "assets/img/Cabeza Gnomo.png",textColor);
	textureManager.createTexture(TextureID::PriestHead,"assets/img/Sacerdote Cabeza Sprite.png", textColor);
	textureManager.createTexture(TextureID::ZombieBody, "assets/img/Zombie Cuerpo Sprite.png",textColor);
	textureManager.createTexture(TextureID::BlueTunic,"assets/img/Tunica Azul Sprite.png", textColor);
	textureManager.createTexture(TextureID::PriestBody, "assets/img/Sacerdote Sprite.png",textColor);
	textureManager.createTexture(TextureID::LeatherArmor, "assets/img/Armadura de Cuero Sprite.png",textColor);
	textureManager.createTexture(TextureID::PlateArmor, "assets/img/Armadura de Placas Sprite.png",textColor);
	textureManager.createTexture(TextureID::BlueCommonBody, "assets/img/Vestimenta Comun azul Sprite.png",textColor);
	textureManager.createTexture(TextureID::GreenCommonBody, "assets/img/Vestimenta Comun verde Sprite.png",textColor);
	textureManager.createTexture(TextureID::RedCommonBody, "assets/img/Vestimenta Comun roja Sprite.png",textColor);
	textureManager.createTexture(TextureID::TortleShield, "assets/img/Escudo de Tortuga Sprite.png",textColor);
	textureManager.createTexture(TextureID::IronHelmet, "assets/img/Casco de Hierro Sprite.png", textColor);
	textureManager.createTexture(TextureID::AshStick, "assets/img/Vara de Fresno Sprite.png", textColor);
	textureManager.createTexture(TextureID::MagicHat, "assets/img/Sombrero Magico Sprite.png", textColor);
	textureManager.createTexture(TextureID::Spider, "assets/img/Araña Sprite.png",textColor);

	MusicManager musicManager;
	musicManager.createMusic(MusicID::Start, "assets/sound/Musica Inicio.mp3");
	const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

	Presentation presentation(window, textureManager);
	presentation.run();

	Spider spider(textureManager, 250,475);
	Priest priest(textureManager, 302, 1026);
	Player player(textureManager, std::move(playerInfo));
	Zombie zombie(textureManager, 478, 145);
	Chrono chrono;
	double initLoop, endLoop, sleep;

	Camera camera(window, gameMap.getMapWidth(), gameMap.getMapHeight());
	while (!quit) {
		initLoop = chrono.lap();
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_m) {
					musica.pauseMusic();
				}
				player.handleEvent(event, serverProxy);
				priest.handleEvent(event);
				zombie.handleEvent(event);
			}
			window.handleEvent(event);
		}
		window.clearScreen();
		Point* center = player.getCenter();
		camera.setPlayer(center);
		camera.moveTo(*center);
        gameMap.draw(camera);
		player.render(camera);
		priest.render(camera);
		zombie.render(camera);
		window.render();
		endLoop = chrono.lap();
		sleep = GAMELOOPTIME - (endLoop - initLoop);
		if (sleep > 0)
			usleep(sleep);
	}

}