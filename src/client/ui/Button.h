#ifndef BUTTON_H
#define BUTTON_H

#include "../Font.h"
#include "../TextureManager.h"

class Button {
protected:
    std::string text;
    SDL_Rect button;
    int textSize{8};
    SDL_Texture* texture = nullptr;
    const TextureManager& manager;
    SDL_Renderer* renderer;
    SDL_Rect viewport{0,0,0,0};
    bool clicked;
    
public:
    Button(SDL_Renderer* renderer, Font& font,std::string text, SDL_Rect position, const TextureManager& manager) :
        text(text), button(position), manager(manager), renderer(renderer), clicked(false) {
        int w,h;
        font.setSize(this->textSize);
        this->texture = font.createText(text,renderer,&w,&h);  
    }
    
    Button(SDL_Renderer* renderer,SDL_Rect position, const TextureManager& manager) :
    button(position), manager(manager),  renderer(renderer), clicked(false){}

    virtual bool inside(int x, int y) = 0;

    virtual void render() = 0;

    void onClick() {
        this->clicked = !this->clicked;
    }

    void setViewport(SDL_Rect viewport) {
        this->viewport = viewport;
    }

    ~Button() {
        SDL_DestroyTexture(this->texture);
    }
};

#endif