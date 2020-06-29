#ifndef RAISEDBUTTON_H
#define RAISEDBUTTON_H

#include "Button.h"

class RaisedButton : public Button {
public:
    RaisedButton(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position, const TextureManager& manager);
    
    virtual bool inside(int x, int y);

    virtual void render();

    void onClick();

    void setViewport(SDL_Rect viewport);

    ~RaisedButton();

};

#endif
