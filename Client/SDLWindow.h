#ifndef SDLWINDOW_H
#define SDLWINDOW_H

class SDL_Window;
class SDL_Renderer;
union SDL_Event;

class SDLWindow {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isMinimized;
	bool isFullScreen;
	int height;
	int width;

public:
	SDLWindow(const int height,const int width,const char* title);

	void clearScreen();

	void render();

	void handleEvent(SDL_Event& event);

	SDL_Renderer* getRenderer();

	~SDLWindow();
};

#endif
