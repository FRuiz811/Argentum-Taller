#ifndef CUREBUTTON_H
#define CUREBUTTON_H

#include "RaisedButton.h"
#include "../Player.h"

class CureButton: public RaisedButton {
private:
    Player* player;
public:
    CureButton(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position,
     const TextureManager& manager,Player* player);
    
    virtual bool inside(int x, int y);

    virtual void render();

    virtual InputInfo onClick(int item);

    void setViewport(SDL_Rect viewport);

    virtual ~CureButton();
};

#endif
