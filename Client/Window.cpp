#include "Window.h"
#include <exception>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include "Exception.h"

#define CHANNELS 2
#define MIX_CHUNKSIZE 1024

Window::Window(const int height, const int width, const char* title) :
	 isMinimized(false), height(height), width(width) {

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
		throw Exception("Error with SDL_Init: %s",SDL_GetError());

	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 
									CHANNELS, MIX_CHUNKSIZE) == -1) {
			throw Exception("Fail Mix_OpenAudio: %s", Mix_GetError());
	}

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		throw Exception("Fail IMG_Init: %s", IMG_GetError());
	}

	if(TTF_Init() == -1)
		throw Exception("Fail TTF_Init: %s", TTF_GetError());

	Uint32 flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED;
	if (SDL_CreateWindowAndRenderer(width, height, flags, &this->window,
									&this->renderer)) 
		throw Exception("Error with SDL_CreateWindowAndRenderer: %s",SDL_GetError());
	SDL_SetWindowTitle(this->window,title);
}

void Window::clearScreen() {
	SDL_SetRenderDrawColor(this->renderer, 0x00, 0x78, 0xFF, 0xFF);
	SDL_RenderClear(this->renderer);
}

void Window::handleEvent(SDL_Event& event) {
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

void Window::render() {
	if (!this->isMinimized) {
		SDL_RenderPresent(this->renderer);
	}
}

SDL_Renderer& Window::getRenderer() const {
	return *this->renderer;
}

int Window::getWidth() const {
	return this->width;
}


int Window::getHeight() const {
	return this->height;
}

Window::~Window() {
	if (this->window) {
		SDL_DestroyWindow(this->window);
		this->window = nullptr;
	}

	if (this->renderer){
		SDL_DestroyRenderer(this->renderer);
		this->renderer = nullptr;
	}
	IMG_Quit();
	TTF_Quit();
	Mix_Quit();
	SDL_Quit();
}