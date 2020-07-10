#include "NPCInterface.h"
#include "SellButton.h"
#include "ResurrectButton.h"
#include "BuyButton.h"
#include "CureButton.h"
#include "RetireGoldButton.h"
#include "DepositGoldButton.h"
#include "DepositItemButton.h"
#include "RetireItemButton.h"

NPCInterface::NPCInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player)
     : information(info), window(window), manager(manager), player(player),
     font("assets/font/Prince Valiant.ttf",18,{0xA4, 0xA4, 0xA4}){}

std::shared_ptr<RaisedButton> NPCInterface::createButtonAction(ActionsProfessionID action,SDL_Rect rect) {
    std::string text;
    std::shared_ptr<RaisedButton> button;
    switch (action) {
    case ActionsProfessionID::Buy:
        text = "Comprar";
        button = std::shared_ptr<RaisedButton>(new BuyButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::Sell:
        text = "Vender";
        button = std::shared_ptr<RaisedButton>(new SellButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::Resurrect:
        text = "Resucitar";
        button = std::shared_ptr<RaisedButton>(new ResurrectButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::Cure:
        text = "Curar";
        button = std::shared_ptr<RaisedButton>(new CureButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::DepositGold:
        text ="Depositar";
        button = std::shared_ptr<RaisedButton>(new DepositGoldButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::DepositItem:
        text = "Depositar";
        button = std::shared_ptr<RaisedButton>(new DepositItemButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::RetireItem:
        text = "Retirar";
        button = std::shared_ptr<RaisedButton>(new RetireItemButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    case ActionsProfessionID::RetireGold:
        text = "Retirar";
        button = std::shared_ptr<RaisedButton>(new RetireGoldButton(&(window->getRenderer()),font,text,rect, manager,player));
        break;
    }
    return button;
}


NPCInterface::~NPCInterface() {
    SDL_DestroyTexture(this->texture);
}