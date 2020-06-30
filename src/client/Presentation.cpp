#include "Presentation.h"
#include <SDL2/SDL.h>
#include "Texture.h"
#include "Font.h"

Presentation::Presentation(Window& window, TextureManager& manager) :
    window(window), manager(manager) {}

bool Presentation::run() {
    bool quit = false;
    bool closeProgram = false;
	int width_text, height_text;
    SDL_Event event;
    SDL_Rect dest;
    const Texture& fondo = this->manager.getTexture(TextureID::PresentationImage);
    std::string fuente = "assets/font/Prince Valiant.ttf";

    SDL_Color textColor = {0xFF, 0xFF, 0xFF};
    Font font(fuente, 18, textColor);
	font.setColor(textColor);
	SDL_Texture* messageTexture = font.createText("Presionar ENTER para continuar",
                                &(window.getRenderer()), &width_text, &height_text);
    
    while (!quit) {

		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
                closeProgram = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym  == SDLK_RETURN){				
					quit = true;
			}
        }
        window.clearScreen();
        fondo.render();
        dest = {(window.getWidth() - width_text) / 2, (window.getHeight() - height_text)* 6/7, width_text, height_text};
		SDL_RenderCopy(&(window.getRenderer()), messageTexture, NULL, &dest);
		window.render();
        }
    }
    font.deleteText(messageTexture);
    return closeProgram;
}

Presentation::~Presentation(){}