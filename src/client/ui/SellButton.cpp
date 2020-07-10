#include "SellButton.h"

SellButton::SellButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo SellButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->sell(item);
}

bool SellButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void SellButton::render() {
    RaisedButton::render();
}

void SellButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

SellButton::~SellButton(){}