#ifndef BANKERINTERFACE_H
#define BANKERINTERFACE_H

#include "NPCInterface.h"
#include <vector>
#include <memory>
#include "RaisedButton.h"
#include "SelectButton.h"
#include "ArrowButton.h"

class BankerInterface: public NPCInterface {
private:
    std::vector<std::shared_ptr<RaisedButton>> buttonsNPC; //Botones que nos muestra el NPC
    std::vector<std::shared_ptr<SelectButton>> buttonsItemsNPC; //Items que nos muestra el NPC
    std::shared_ptr<ArrowButton> changeScreen{nullptr};
    std::vector<std::shared_ptr<ArrowButton>> arrows;
    bool pageGold{true};
    int amountGold{0};
    SDL_Texture* goldValue{nullptr};
    SDL_Texture* inBank{nullptr}; 
    SDL_Texture* goldInBank{nullptr};
    int itemSelectedNPC{-1};
    uint pagItemsInBank{0}; //La página que nos está mostrando el NPC de los items depositados
    uint pagMaxInBank{0}; //La cantidad de páginas que se va a tener con el NPC
    std::shared_ptr<ArrowButton> arrow{nullptr};

    void renderGoldManagment();
    void renderItems();
public:
    explicit BankerInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player);

    virtual void render();

    virtual InputInfo handleClick(int x, int y, int itemSelected);

    ~BankerInterface();

};

#endif
