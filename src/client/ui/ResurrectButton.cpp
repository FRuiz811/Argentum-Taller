#include "ResurrectButton.h"

ResurrectButton::ResurrectButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo ResurrectButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->resurrect();
}

bool ResurrectButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void ResurrectButton::render() {
    RaisedButton::render();
}

void ResurrectButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

ResurrectButton::~ResurrectButton(){}