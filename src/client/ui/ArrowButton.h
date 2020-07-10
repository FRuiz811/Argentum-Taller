#ifndef ARROWBUTTON_H
#define ARROWBUTTON_H

#include "Button.h"
#include "../Player.h"

class ArrowButton: public Button {
public:
    ArrowButton(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position,
     const TextureManager& manager);
    
    virtual bool inside(int x, int y);

    virtual void render();

    virtual void onClick();

    void setViewport(SDL_Rect viewport);

    virtual ~ArrowButton();
};

#endif
