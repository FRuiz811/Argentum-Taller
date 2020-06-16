#ifndef WINDOW_H
#define WINDOW_H

class SDL_Window;
class SDL_Renderer;
union SDL_Event;

class Window {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isMinimized;
	int height;
	int width;
	void init();
	const char* title;
public:
	Window(const char* title);
	Window(const int height,const int width,const char* title);

	void clearScreen();

	void render();

	void handleEvent(SDL_Event& event);

	SDL_Renderer& getRenderer() const;

	int getWidth() const;
    int getHeight() const;

	~Window();

	Window(const Window&) = delete;
    Window &operator=(const Window&) = delete;
};

#endif
