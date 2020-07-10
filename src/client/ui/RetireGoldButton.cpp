#include "RetireGoldButton.h"

RetireGoldButton::RetireGoldButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo RetireGoldButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->buy(item);
}

bool RetireGoldButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void RetireGoldButton::render() {
    RaisedButton::render();
}

void RetireGoldButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

RetireGoldButton::~RetireGoldButton(){}