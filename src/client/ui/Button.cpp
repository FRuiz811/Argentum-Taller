#include "Button.h"

Button::Button(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position, 
    const TextureManager& manager) : text(text), button(position), manager(manager), 
    renderer(renderer), clicked(false) {
    int w,h;
    font.setSize(this->textSize);
    this->texture = font.createText(text,renderer,&w,&h);  
}

Button::Button(SDL_Renderer* renderer,SDL_Rect position, const TextureManager& manager) :
    button(position), manager(manager),  renderer(renderer), clicked(false){}

void Button::onClick() {
        this->clicked = !this->clicked;
}

void Button::updatePosition(SDL_Rect position) {
    this->button = position;
}

void Button::setViewport(SDL_Rect viewport) {
        this->viewport = viewport;
}

Button::~Button() {
        SDL_DestroyTexture(this->texture);
}