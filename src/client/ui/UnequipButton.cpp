#include "UnequipButton.h"

UnequipButton::UnequipButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo UnequipButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->unequipItem(item);
}

bool UnequipButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void UnequipButton::render() {
    RaisedButton::render();
}

void UnequipButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

UnequipButton::~UnequipButton(){}