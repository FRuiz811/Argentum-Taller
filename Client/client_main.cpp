#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <utility>
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "TextureManager.h"
#include "TextureID.h"
#include "Font.h"

#define ARGENTUM "Argentum Online"

int main(int argc, char* args[]) {
	bool quit = false;
	std::string presentation = "assets/img/ImagenPresentacion.jpg";
	std::string lobby = "assets/img/Fondo Inicio.jpg";
	std::string music = "assets/sound/Musica Inicio.mp3";
	std::string fuente = "assets/font/Prince Valiant.ttf";

	SDL_Event event;
	Window window(ARGENTUM);
	SDL_Color textColor = {0x0, 0x0, 0x0};
	Font font(fuente, 18, textColor);
	TextureManager textureManager(window.getRenderer());
	textureManager.createTexture(TextureID::PresentationImage, presentation);
	textureManager.createTexture(TextureID::LobbyBackground, lobby);
	Texture& fondo = textureManager.getTexture(TextureID::PresentationImage);
	Texture& lobbyTexture = textureManager.getTexture(TextureID::LobbyBackground);
	Music musica(music);
	musica.playMusic(-1);

	textColor = {0xFF, 0xFF, 0xFF};
	font.setColor(textColor);
	int width_text, height_text;
	std::string message = "Presionar ENTER para continuar";
	SDL_Texture* messageTexture = font.createText(message,&(window.getRenderer()), &width_text, &height_text);
	SDL_Rect dest;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym  == SDLK_RETURN){				
					messageTexture = nullptr;
				}
			}
			window.handleEvent(event);
		}
		dest = {(window.getWidth() - width_text) / 2, (window.getHeight() - height_text)* 6/7, width_text, height_text};
		window.clearScreen();
		if(messageTexture)
			fondo.render();
		else
			lobbyTexture.render();
		SDL_RenderCopy(&(window.getRenderer()), messageTexture, NULL, &dest);
		window.render();
	}
}