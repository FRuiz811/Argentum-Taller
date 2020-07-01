#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "Window.h"
#include "../common/Point.h"
#include "Player.h"
#include "Font.h"
#include "SelectButton.h"
#include "RaisedButton.h"
#include <vector>

union SDL_Event;

class UI {
private:
    Player* playerTarget = nullptr; //Jugador del cual debe mostrar estadisticas.
    Window& window;
    const TextureManager& manager;
    Font font;
    std::vector<SDL_Texture*> texts;
    std::vector<SDL_Texture*> info;
    std::vector<std::shared_ptr<RaisedButton>> buttonsInventory;
    std::vector<std::shared_ptr<SelectButton>> buttonsItems;
    int widthSegment;
    int itemSelected = -1;
    void updateStates();
    void updateHealth();
    void updateMana();
    void updateGold();
    void updateLevelAndExpirience();
    void deleteInfo();
    void updateInventory();
    void updateItems();
    void updateEquipment();
    void updateInteract();
    void updateBuild();
public:
    UI(Window& window, Player* player, const TextureManager& manager);

    void render();

    InputInfo handleClick(SDL_Event& event);

    ~UI();
};

#endif