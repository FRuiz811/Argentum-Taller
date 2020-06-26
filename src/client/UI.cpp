#include "UI.h"

UI::UI(Window& window, Player* player, const TextureManager& manager) : 
window(window), playerTarget(player), manager(manager) {}

void UI::updateStates() {
    const Texture& topBar = manager.getTexture(TextureID::TopBar);
    SDL_Rect topBarViewport;
    topBarViewport.x = 0;
    topBarViewport.y = 0;
    topBarViewport.w = this->window.getWidth();
    topBarViewport.h = 50;
    SDL_RenderSetViewport(&(this->window.getRenderer()), &topBarViewport);
    SDL_RenderCopy(&(this->window.getRenderer()), topBar.getTexture(), NULL, NULL);
}

void UI::render() {
    updateStates();
}

UI::~UI() {}