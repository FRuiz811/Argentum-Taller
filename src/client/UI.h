#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "../common/Point.h"
#include "Player.h"

class UI {
private:
    Player* playerTarget = nullptr; //Jugador del cual debe mostrar estadisticas.
    Window& window;
    const TextureManager& manager;

    void updateStates();
    
public:
    UI(Window& window, Player* player, const TextureManager& manager);

    void render();

    ~UI();
};

#endif