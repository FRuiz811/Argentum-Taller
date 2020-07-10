#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "../Window.h"
#include "../../common/Point.h"
#include "../Player.h"
#include "../Font.h"
#include "SelectButton.h"
#include "RaisedButton.h"
#include "ArrowButton.h"
#include <vector>
#include "NPCInterface.h"
union SDL_Event;

class UI {
private:
    Player* playerTarget = nullptr; //Jugador del cual debe mostrar estadisticas.
    Window& window;
    const TextureManager& manager;
    Font font;
    std::shared_ptr<NPCInterface> npc{nullptr};

    std::vector<SDL_Texture*> texts; //Textos que se muestran en la interfaz
    std::vector<SDL_Texture*> info; //Informacion de los stats del jugador
    std::vector<std::shared_ptr<RaisedButton>> buttonsInventory; //Botones del inventario
    std::vector<std::shared_ptr<SelectButton>> buttonsItems; //Items mostrados en el inventario

    NPCInfo informationNPC;
    int widthSegment;
    int itemSelected{-1};

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
    void createTexts();
    
public:
    UI(Window& window, Player* player, const TextureManager& manager);

    void render();

    void setNPCInfo(NPCInfo info);

    InputInfo handleClick(SDL_Event& event);

    ~UI();
};

#endif