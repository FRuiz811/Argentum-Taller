#include "SDLWindow.h"
#include <exception>
#include <SDL2/SDL.h>

SDLWindow::SDLWindow(const int height, const int width, const char* title) :
	 isMinimized(false), isFullScreen(false), height(height), width(width) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		throw std::exception();
	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED;
	if (SDL_CreateWindowAndRenderer(width, height, flags, &this->window,
									&this->renderer)) 
		throw std::exception();
	SDL_SetWindowTitle(this->window,title);
}

void SDLWindow::clearScreen() {
	SDL_SetRenderDrawColor(this->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(this->renderer);
}

void SDLWindow::handleEvent(SDL_Event& event) {
	if(event.type == SDL_WINDOWEVENT) {
		switch(event.window.event) {
			//Redimenciona el tamaño de la ventana.
			case SDL_WINDOWEVENT_SIZE_CHANGED:
				this->width = event.window.data1;
				this->height = event.window.data2;
				render();
				break;
			//Repaint on exposure
			case SDL_WINDOWEVENT_EXPOSED:
				render();
				break;
			//Window minimized
			case SDL_WINDOWEVENT_MINIMIZED:
        this->isMinimized = true;
        break;
			//Window maxized
			case SDL_WINDOWEVENT_MAXIMIZED:
			 this->isMinimized = false;
       break;
			//Window restored
			case SDL_WINDOWEVENT_RESTORED:
			 this->isMinimized = false;
       break;
		}
}
}

void SDLWindow::render() {
	if (!this->isMinimized) {
		SDL_RenderPresent(this->renderer);
	}
}

SDL_Renderer* SDLWindow::getRenderer() {
	return this->renderer;
}

SDLWindow::~SDLWindow() {
	if (this->window) {
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}

	if (this->renderer){
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}
}