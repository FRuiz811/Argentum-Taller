#include "EquipButton.h"

EquipButton::EquipButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo EquipButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->selectItem(item);
}

bool EquipButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void EquipButton::render() {
    RaisedButton::render();
}

void EquipButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

EquipButton::~EquipButton(){}