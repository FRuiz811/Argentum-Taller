#include "SDL2/SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "TextureManager.h"
#include "GameTexture.h"
#include <SDL2/SDL_mixer.h>

#define ARGENTUM "Argentum Online"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main(int argc, char* args[]) {
	bool quit = false;
	std::string path = "assets/img/ImagenPresentacion.jpg";
	std::string music = "assets/sound/Musica Inicio.mp3";
	SDL_Event events;
	Window window(WINDOW_HEIGHT, WINDOW_WIDTH, ARGENTUM);
	TextureManager textureManager(window.getRenderer());
	textureManager.createTexture(GameTexture::PresentationImage, path);
	Music musica(music);
	musica.playMusic(-1);
	Texture fondo = std::move(textureManager.getTexture(GameTexture::PresentationImage));
	while (!quit) {
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) {
				quit = true;
			}
			window.handleEvent(events);
		}
		window.clearScreen();
		fondo.render();
		window.render();
	}
}