#include "SDL2/SDL.h"
#include "SDLWindow.h"

#define ARGENTUM "Argentum Online"
#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800
int main(int argc, char* args[]) {
	bool quit = false;
	SDL_Event events;
	SDLWindow window(WINDOW_HEIGHT, WINDOW_WIDTH, ARGENTUM);

	while (!quit) {
		while (SDL_PollEvent(&events) != 0) {
			if (events.type == SDL_QUIT) 
				quit = true;
		}
	}
}