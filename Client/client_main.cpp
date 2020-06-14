#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include <utility>
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "TextureManager.h"
#include "TextureID.h"
#include "Font.h"
#include <iostream>

#define ARGENTUM "Argentum Online"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main(int argc, char* args[]) {
	bool quit = false;
	std::string presentation = "assets/img/ImagenPresentacion.jpg";
	std::string lobby = "assets/img/Fondo Inicio.jpg";
	std::string music = "assets/sound/Musica Inicio.mp3";
	std::string fuente = "assets/font/Prince Valiant.ttf";

	SDL_Event event;
	Window window(WINDOW_HEIGHT, WINDOW_WIDTH, ARGENTUM);

	Font font(fuente, 18);
	TextureManager textureManager(window.getRenderer());
	textureManager.createTexture(TextureID::PresentationImage, presentation);
	textureManager.createTexture(TextureID::LobbyBackground, lobby);
	Texture& fondo = textureManager.getTexture(TextureID::PresentationImage);
	Texture& lobbyTexture = textureManager.getTexture(TextureID::LobbyBackground);
	Music musica(music);
	musica.playMusic(-1);

	SDL_Color textColor = {0xFF, 0xFF, 0xFF};
	SDL_Surface* textSurface = TTF_RenderText_Solid(font.getFont(), "Presionar ENTER para continuar", textColor);
	SDL_Texture* message = SDL_CreateTextureFromSurface(&(window.getRenderer()), textSurface);
	int width_text = textSurface->w;
	int height_text = textSurface->h;

	SDL_Rect dest = {(window.getWidth() - width_text) / 2, (window.getHeight() - height_text)*6 / 7, width_text, height_text};
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym  == SDLK_RETURN){				
					message = nullptr;
				}
			}
			window.handleEvent(event);
		}
		dest = {(window.getWidth() - width_text) / 2, (window.getHeight() - height_text)*6 / 7, width_text, height_text};
		window.clearScreen();
		if(message)
			fondo.render();
		else
			lobbyTexture.render();
		SDL_RenderCopy(&(window.getRenderer()), message, NULL, &dest);
		window.render();
	}
}