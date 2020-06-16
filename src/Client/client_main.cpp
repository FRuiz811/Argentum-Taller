#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <utility>
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "MusicManager.h"
#include "TextureManager.h"
#include "TextureID.h"
#include "MusicID.h"
#include "Font.h"
#include "Zombie.h"
#include "../JsonReader.h"
#include "../MapTransformer.h"
#include "GameMap.h"
#include "Player.h"
#include "Spider.h"


#define ARGENTUM "Argentum Online"

int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Color textColor = {0x0, 0x0, 0x0};
	std::string fuente = "assets/font/Prince Valiant.ttf";
	int width_text, height_text;
	SDL_Rect dest;

	SDL_Event event;
	Window window(ARGENTUM);
    JsonReader jsonReader;
    rapidjson::Document jsonMap = jsonReader.read("json/tiledMap.json");
    MapTransformer mapTransformer;
    TiledMap tiledMap = mapTransformer.transform(jsonMap);
    GameMap gameMap(tiledMap, window.getRenderer());

	TextureManager textureManager(window.getRenderer());
	textureManager.createTexture(TextureID::PresentationImage, "assets/img/ImagenPresentacion.jpg");
	textureManager.createTexture(TextureID::LobbyBackground, "assets/img/Fondo Inicio.jpg");
	textureManager.createTexture(TextureID::ZombieHead, "assets/img/Zombie Cabeza.png",textColor);
	textureManager.createTexture(TextureID::ZombieBody, "assets/img/Zombie Cuerpo Sprite.png",textColor);
	textureManager.createTexture(TextureID::Spider, "assets/img/Araña Sprite.png",textColor);
	textureManager.createTexture(TextureID::ElfHead,"assets/img/Cabeza Elfo.png", textColor);
	textureManager.createTexture(TextureID::BlueTunic,"assets/img/Tunica Azul Sprite.png", textColor);
	textureManager.createTexture(TextureID::TortleShield, "assets/img/Escudo de Tortuga Sprite.png",textColor);
	textureManager.createTexture(TextureID::IronHelmet, "assets/img/Casco de Hierro Sprite.png", textColor);
	textureManager.createTexture(TextureID::AshStick, "assets/img/Vara de Fresno Sprite.png", textColor);
	textureManager.createTexture(TextureID::MagicHat, "assets/img/Sombrero Magico Sprite.png", textColor);
	const Texture& fondo = textureManager.getTexture(TextureID::PresentationImage);
	const Texture& lobbyTexture = textureManager.getTexture(TextureID::LobbyBackground);

	MusicManager musicManager;
	musicManager.createMusic(MusicID::Start, "assets/sound/Musica Inicio.mp3");
	const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

	Font font(fuente, 18, textColor);
	textColor = {0xFF, 0xFF, 0xFF};
	font.setColor(textColor);
	SDL_Texture* messageTexture = font.createText("Presionar ENTER para continuar",&(window.getRenderer()), &width_text, &height_text);
	Spider spider(textureManager);
	Player player(textureManager);
	while (!quit) {

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym  == SDLK_RETURN){				
					messageTexture = nullptr;
				}
				player.handleEvent(event);
				spider.handleEvent(event);
			}
			window.handleEvent(event);
		}
		window.clearScreen();

		if(messageTexture)
			fondo.render();
		else {
            gameMap.draw(window.getRenderer());
			player.render(window.getWidth(), window.getHeight());
			spider.render(window.getWidth(), window.getHeight());
		}

		dest = {(window.getWidth() - width_text) / 2, (window.getHeight() - height_text)* 6/7, width_text, height_text};
		SDL_RenderCopy(&(window.getRenderer()), messageTexture, NULL, &dest);
		window.render();
	}

	SDL_DestroyTexture(messageTexture);
}