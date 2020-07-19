#include "SelectButton.h"

SelectButton::SelectButton(SDL_Renderer* renderer, SDL_Rect position, const TextureManager& manager, int id) :
    Button(renderer,position,manager), id(id){}

void SelectButton::render(){
    int w,h;
    const Texture& background = manager.getTexture(TextureID::Button);
    SDL_QueryTexture(background.getTexture(), NULL, NULL, &w, &h);
    SDL_Rect src = {0,0,w,h};
    background.render(src,this->button);
    if(this->clicked) {
        SDL_Rect click = {button.x-1,button.y-1,button.w+2,button.h+2};
        SDL_SetRenderDrawColor(this->renderer, 0xA4, 0xA4, 0xA4, 0xAA);		
    	SDL_RenderDrawRect(this->renderer, &click);
    }
    if(this->texture != nullptr){
        SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
        src = {0,0,w,h};
        SDL_Rect dest = {button.x+w/4, button.y,w,h};
        SDL_RenderCopy(this->renderer,this->texture,&src,&dest);
    }
}

void SelectButton::onClick() {
    this->clicked = !this->clicked;
}

void SelectButton::updatePosition(SDL_Rect position) {
    Button::updatePosition(position);
}

bool SelectButton::inside(int x, int y) {
    bool inside = true;
    if (x < this->button.x+viewport.x)
        inside = false;
    if (x > this->button.x+this->button.w+viewport.x)
        inside = false;
    if (y < this->button.y+viewport.y)
        inside = false;
    if (y > this->button.y + this->button.h+viewport.y)
        inside = false;
    if (inside)
        onClick();
    return inside;
}

int SelectButton::getId() {
    return this->id;
}

void SelectButton::setViewport(SDL_Rect viewport) {
    this->viewport = viewport;
}

SelectButton::~SelectButton(){}