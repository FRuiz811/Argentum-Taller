#include "ArrowButton.h"

ArrowButton::ArrowButton(SDL_Renderer* renderer, Font& font,std::string text,
    SDL_Rect position, const TextureManager& manager) : 
        Button(renderer,font,text,position,manager) {}

bool ArrowButton::inside(int x, int y) {
     bool inside = true;
    if (x < this->button.x+viewport.x)
        inside = false;
    if (x > this->button.x+this->button.w+viewport.x)
        inside = false;
    if (y < this->button.y+viewport.y)
        inside = false;
    if (y > this->button.y + this->button.h+viewport.y)
        inside = false;
    return inside;
}

void ArrowButton::onClick() {
    this->clicked = !this->clicked;
}

void ArrowButton::render() {
   int w,h;
    const Texture& background = manager.getTexture(TextureID::Button);
    SDL_QueryTexture(background.getTexture(), NULL, NULL, &w, &h);
    SDL_Rect src = {0,0,w,h};
    background.render(src,this->button);
    if(this->clicked) {
        SDL_Rect click = {button.x-1,button.y-1,button.w+2,button.h+2};
        SDL_SetRenderDrawColor(this->renderer, 0xA4, 0xA4, 0xA4, 0xAA);		
    	SDL_RenderDrawRect(this->renderer, &click);
        this->clicked = !this->clicked;
    }
     if(this->texture != nullptr){
        SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
        src = {0,0,w,h};
        SDL_Rect dest = {button.x, button.y-button.h,w*2,h*2};
        SDL_RenderCopy(this->renderer,this->texture,&src,&dest);
    }
}

void ArrowButton::setViewport(SDL_Rect viewport){
    Button::setViewport(viewport);
}

ArrowButton::~ArrowButton(){}