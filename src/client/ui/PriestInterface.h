#ifndef PRIESTINTERFACE_H
#define PRIESTINTERFACE_H

#include "NPCInterface.h"
#include <vector>
#include <memory>
#include "RaisedButton.h"
#include "SelectButton.h"

class PriestInterface: public NPCInterface {
private:
    std::vector<std::shared_ptr<RaisedButton>> buttonsNPC; //Botones que nos muestra el NPC
    std::vector<std::shared_ptr<SelectButton>> buttonsItemsNPC; //Items que nos muestra el NPC
    std::vector<SDL_Texture*> gold; //El oro que se salen cada uno de los items
    std::vector<ItemsInventoryID> itemsPriest;
    int itemSelectedNPC{-1};

    void deleteGoldValues();
public:
    explicit PriestInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player);

    virtual void render();

    virtual InputInfo handleClick(int x, int y, int itemSelected);

    ~PriestInterface();

};


#endif