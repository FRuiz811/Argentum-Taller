#include "CureButton.h"

CureButton::CureButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo CureButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->cure();
}

bool CureButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void CureButton::render() {
    RaisedButton::render();
}

void CureButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

CureButton::~CureButton(){}