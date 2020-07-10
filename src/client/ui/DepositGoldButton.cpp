#include "DepositGoldButton.h"

DepositGoldButton::DepositGoldButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo DepositGoldButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->buy(item);
}

bool DepositGoldButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void DepositGoldButton::render() {
    RaisedButton::render();
}

void DepositGoldButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

DepositGoldButton::~DepositGoldButton(){}