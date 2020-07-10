#include "RetireItemButton.h"

RetireItemButton::RetireItemButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo RetireItemButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->buy(item);
}

bool RetireItemButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void RetireItemButton::render() {
    RaisedButton::render();
}

void RetireItemButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

RetireItemButton::~RetireItemButton(){}