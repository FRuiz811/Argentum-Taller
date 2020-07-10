#include "DropButton.h"

DropButton::DropButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager,Player* player) : 
        RaisedButton(renderer,font,text,position,manager), player(player) {}

InputInfo DropButton::onClick(int item) {
    this->clicked = !this->clicked;
    return this->player->dropItem(item);
}

bool DropButton::inside(int x, int y) {
    return RaisedButton::inside(x,y);
}

void DropButton::render() {
    RaisedButton::render();
}

void DropButton::setViewport(SDL_Rect viewport){
    RaisedButton::setViewport(viewport);
}

DropButton::~DropButton(){}