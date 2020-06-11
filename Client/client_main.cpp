#include "SDL2/SDL.h"
#include "SDLWindow.h"
#include "SDLTexture.h"
#include "SDLMusic.h"
#include <SDL2/SDL_mixer.h>

#define ARGENTUM "Argentum Online"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event events;
	SDLWindow window(WINDOW_HEIGHT, WINDOW_WIDTH, ARGENTUM);
	std::string path = "Media/ImagenPresentacion.jpg";
	std::string music = "Media/Musica Inicio.mp3";
	SDLTexture fondo(path, window);
	SDLMusic musica(music);
	musica.playMusic(-1);
	
	while (!quit) {
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) 
				quit = true;
			window.handleEvent(events);
		}
		window.clearScreen();
		fondo.render();
		window.render();
	}
}