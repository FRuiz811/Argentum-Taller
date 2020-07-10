#include "DepositItemButton.h"

DepositItemButton::DepositItemButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo DepositItemButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->deposit(item, true);
}

bool DepositItemButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void DepositItemButton::render() {
    RaisedButton::render();
}

void DepositItemButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

DepositItemButton::~DepositItemButton(){}