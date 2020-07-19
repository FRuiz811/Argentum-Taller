#ifndef RAISEDBUTTON_H
#define RAISEDBUTTON_H

#include "Button.h"

class RaisedButton : public Button {
public:
    RaisedButton(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position, const TextureManager& manager);
    
    virtual bool inside(int x, int y);

    virtual void render();

    virtual InputInfo onClick(int item) = 0;

    void setViewport(SDL_Rect viewport);

    virtual void updatePosition(SDL_Rect position);

    virtual ~RaisedButton();

};

#endif
