#ifndef UI_H
#define UI_H

#include <SDL2/SDL.h>
#include "../Window.h"
#include "../../common/Point.h"
#include "../Player.h"
#include "../Font.h"
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
    std::vector<std::shared_ptr<RaisedButton>> buttonsNPC;
    std::vector<std::shared_ptr<SelectButton>> buttonsItemsNPC;
    std::vector<SDL_Texture*> gold;
    NPCInfo informationNPC;
    int widthSegment;
    int itemSelected{-1};
    int itemSelectedNPC{-1};

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
    void generateMerchant();
    void generatePriest();
    void generateBanker();
    void deleteGoldValues();

    std::shared_ptr<RaisedButton> createButtonAction(ActionsProfessionID action,SDL_Rect rect);
public:
    UI(Window& window, Player* player, const TextureManager& manager);

    void render();

    void setNPCInfo(NPCInfo info);

    InputInfo handleClick(SDL_Event& event);

    ~UI();
};

#endif