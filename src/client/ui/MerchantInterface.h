#ifndef MERCHANTINTERFACE_H
#define MERCHANTINTERFACE_H

#include "NPCInterface.h"
#include <vector>
#include <memory>
#include "RaisedButton.h"
#include "SelectButton.h"
#include "ArrowButton.h"

class MerchantInterface: public NPCInterface {
private:
    std::vector<std::shared_ptr<RaisedButton>> buttonsNPC; //Botones que nos muestra el NPC
    std::vector<std::shared_ptr<SelectButton>> buttonsItemsNPC; //Items que nos muestra el NPC
    std::vector<SDL_Texture*> gold; //El oro que se salen cada uno de los items
    int itemSelectedNPC{-1};
    uint pagItems{0}; //La página que nos está mostrando el NPC de los items
    uint pagMax{0}; //La cantidad de páginas que se va a tener con el NPC
    std::shared_ptr<ArrowButton> arrow{nullptr};

    void deleteGoldValues();
public:
    explicit MerchantInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player);

    virtual void render();

    virtual InputInfo handleClick(int x, int y, int itemSelected);

    ~MerchantInterface();

};


#endif