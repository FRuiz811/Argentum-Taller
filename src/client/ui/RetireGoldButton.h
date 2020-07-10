#ifndef RETIREGOLDBUTTON_H
#define RETIREGOLDBUTTON_H

#include "RaisedButton.h"
#include "../Player.h"

class RetireGoldButton: public RaisedButton {
private:
    Player* player;
public:
    RetireGoldButton(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position,
     const TextureManager& manager,Player* player);
    
    virtual bool inside(int x, int y);

    virtual void render();

    virtual InputInfo onClick(int item);

    void setViewport(SDL_Rect viewport);

    virtual ~RetireGoldButton();
};

#endif
