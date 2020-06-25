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
#include "GameMap.h"
#include "Player.h"
#include "Camera.h"
#include "../common/Point.h"


#define ARGENTUM "Argentum Online"
#define GAMELOOPTIME 60000

int main(int argc, char* args[]) {
	//Debería ser 5 argc
	//Realizar el connect al host & port indicado.
	ServerProxy serverProxy;
	PlayerInfo playerInfo = serverProxy.createCharacter(0, 0);
	bool quit = false;
	SDL_Event event;

	Window window(ARGENTUM);
    GameMap gameMap(serverProxy.getStaticMap(), window.getRenderer());
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
	textureManager.createTexture(TextureID::TurtleShield, "assets/img/Escudo de Tortuga Sprite.png",textColor);
	textureManager.createTexture(TextureID::IronShield, "assets/img/Escudo de Hierro Sprite.png",textColor);
	textureManager.createTexture(TextureID::IronHelmet, "assets/img/Casco de Hierro Sprite.png", textColor);
	textureManager.createTexture(TextureID::Hood, "assets/img/Capucha Sprite.png",textColor);
	textureManager.createTexture(TextureID::MagicHat, "assets/img/Sombrero Magico Sprite.png", textColor);
	textureManager.createTexture(TextureID::AshStick, "assets/img/Vara de Fresno Sprite.png", textColor);
	textureManager.createTexture(TextureID::LongSword, "assets/img/Espada Larga Sprite.png", textColor);
	textureManager.createTexture(TextureID::Hammer, "assets/img/Martillo Sprite.png", textColor);
	textureManager.createTexture(TextureID::SimpleArc, "assets/img/Arco Simple Sprite.png", textColor);
	textureManager.createTexture(TextureID::CompoundArc, "assets/img/Arco Compuesto Sprite.png", textColor);
	textureManager.createTexture(TextureID::GnarledStick, "assets/img/Baston Nudoso.png", textColor);
	textureManager.createTexture(TextureID::Crosier, "assets/img/Baculo Engarzado Sprite.png", textColor);
	textureManager.createTexture(TextureID::Ax, "assets/img/Hacha Sprite.png", textColor);
	textureManager.createTexture(TextureID::ElficFlaute, "assets/img/Flauta Elfica Sprite.png", textColor);
	textureManager.createTexture(TextureID::Spider, "assets/img/Araña Sprite.png",textColor);
	textureManager.createTexture(TextureID::Skeleton, "assets/img/Esqueleto Sprite.png", textColor);
	textureManager.createTexture(TextureID::Banker, "assets/img/Banquero Sprite.png", textColor);
	textureManager.createTexture(TextureID::Merchant, "assets/img/Comerciante Sprite.png", textColor);
	textureManager.createTexture(TextureID::Goblin, "assets/img/Goblin.png", textColor);
	textureManager.createTexture(TextureID::Ghost, "assets/img/Fantasma Sprite.png", textColor);
	textureManager.createTexture(TextureID::ManaPotion, "assets/img/Pocion Mana.png", textColor);
	textureManager.createTexture(TextureID::HealthPotion, "assets/img/Pocion Vida.png", textColor);
	textureManager.createTexture(TextureID::Gold, "assets/img/Oro.png", textColor);
	textureManager.createTexture(TextureID::ItemHood, "assets/img/Capucha.png", textColor);
	textureManager.createTexture(TextureID::ItemIronHelmet, "assets/img/Casco de Hierro.png", textColor);
	textureManager.createTexture(TextureID::ItemMagicHat, "assets/img/Sombrero Magico.png", textColor);
	textureManager.createTexture(TextureID::ItemIronShield, "assets/img/Escudo de Hierro.png", textColor);
	textureManager.createTexture(TextureID::ItemTurtleShield, "assets/img/Escudo de Tortuga.png", textColor);
	textureManager.createTexture(TextureID::ItemAx, "assets/img/Hacha.png", textColor);
	textureManager.createTexture(TextureID::ItemSimpleArc, "assets/img/Arco Simple.png", textColor);
	textureManager.createTexture(TextureID::ItemCompoundArc, "assets/img/Arco Compuesto.png", textColor);
	textureManager.createTexture(TextureID::ItemHammer, "assets/img/Martillo.png", textColor);
	textureManager.createTexture(TextureID::ItemLongSword, "assets/img/Espada Larga.png", textColor);
	textureManager.createTexture(TextureID::ItemAshStick, "assets/img/Vara de Fresno.png", textColor);
	textureManager.createTexture(TextureID::ItemCrosier, "assets/img/Baculo Engarzado.png", textColor);
	textureManager.createTexture(TextureID::ItemGnarledStick, "assets/img/Baston Nudoso.png", textColor);
	textureManager.createTexture(TextureID::ItemElficFlaute, "assets/img/Flauta Elfica.png", textColor);
	textureManager.createTexture(TextureID::ItemGreenCommonBody, "assets/img/Vestimenta Comun verde.png", textColor);
	textureManager.createTexture(TextureID::ItemBlueCommonBody, "assets/img/Vestimenta Comun azul.png", textColor);
	textureManager.createTexture(TextureID::ItemRedCommonBody, "assets/img/Vestimenta Comun roja.png", textColor);
	textureManager.createTexture(TextureID::ItemBlueTunic, "assets/img/Tunica Azul.png", textColor);
	textureManager.createTexture(TextureID::ItemLeatherArmor, "assets/img/Armadura de Cuero.png", textColor);
	textureManager.createTexture(TextureID::ItemPlateArmor, "assets/img/Armadura de Placas.png", textColor);

	
	MusicManager musicManager;
	musicManager.createMusic(MusicID::Start, "assets/sound/Musica Inicio.mp3");
	const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

	Presentation presentation(window, textureManager);
	if (presentation.run())
		return 0;
	Player player(textureManager, std::move(playerInfo));
	Chrono chrono;
	double initLoop, endLoop, sleep;

	Camera camera(window, gameMap.getMapWidth(), gameMap.getMapHeight());
	InputInfo input;

	while (!quit) {
		initLoop = chrono.lap();
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_m) {
					musica.pauseMusic();
				}
				input = player.handleEvent(event, serverProxy);
				serverProxy.sendInput(input);
			}
			window.handleEvent(event);
		}
		playerInfo = serverProxy.updateModel();
		player.updatePlayerInfo(std::move(playerInfo));
		window.clearScreen();
		Point* center = player.getCenter();
		camera.setPlayer(center);
		camera.moveTo(*center);
        gameMap.drawGround(camera);
		player.render(camera);
		gameMap.draw(camera);
		window.render();
		endLoop = chrono.lap();
		sleep = GAMELOOPTIME - (endLoop - initLoop);
		if (sleep > 0)
			usleep(sleep);
	}
	return 0;
}