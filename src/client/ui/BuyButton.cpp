#include "BuyButton.h"

BuyButton::BuyButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo BuyButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->buy(item);
}

bool BuyButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void BuyButton::render() {
    RaisedButton::render();
}

void BuyButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

BuyButton::~BuyButton(){}