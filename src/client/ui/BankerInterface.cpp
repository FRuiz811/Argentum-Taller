#include "BankerInterface.h"
#include <SDL2/SDL.h>

#include <memory>
#include <utility>

#define WIDTHBUTTON 70
#define HEIGTHBUTTON 25
#define ITEMSBANKER 12

BankerInterface::BankerInterface(NPCInfo info, Window* window, const TextureManager& manager, Player* player) :
    NPCInterface(std::move(info), window, manager, player), buttonsNPC(), buttonsItemsNPC(), arrows() {
    int width_text, height_text;
    SDL_Texture* banker = font.createText("Banquero",
        &(window->getRenderer()), &width_text, &height_text);
    this->texture = banker;
    this->inBank = font.createText("Oro en Banco: ",
        &(window->getRenderer()), &width_text, &height_text);
    SDL_Rect rect = {(this->window->getWidth()/8)*2-40,((this->window->getHeight()-60)/2)-HEIGTHBUTTON*3,20,20};
    this->changeScreen = std::make_shared<ArrowButton>(&(window->getRenderer()),font,">",rect, manager);
}

void BankerInterface::renderGoldManagment() {
    int w,h;
    int i =0;
    SDL_QueryTexture(this->inBank, NULL, NULL, &w, &h);
    SDL_Rect bank = {15, 45, w, h};
    SDL_RenderCopy(&(window->getRenderer()), this->inBank, NULL, &bank);
    bank = {15, 45 + h, w, h};
    this->goldInBank = font.createText(std::to_string(information.gold),
        &(window->getRenderer()), &w, &h);
    bank.w = w;
    bank.h = h;
    SDL_RenderCopy(&(window->getRenderer()), this->goldInBank, NULL, &bank);

    const Texture& goldTexture = manager.getTexture(TextureID::Gold);
    SDL_Rect srcGold = {0,0,32,32};
    SDL_Rect dstGold = {25,140,32,32};
    goldTexture.render(srcGold,dstGold);
    std::string inputText;
    if (this->amountGold == 0) {
        int amount = this->player->getGold() - this->player->getSafeGold();
        if (amount < 0)
            amount = 0;
        inputText = std::to_string(amount);
    }
    inputText = std::to_string(this->amountGold);
    this->goldValue = font.createText(inputText,
        &(window->getRenderer()), &w, &h);
    SDL_Rect gold = {100,140,w,h};
    SDL_RenderCopy(&(window->getRenderer()), this->goldValue, NULL, &gold);

    bool loadButtons =false;
    
    if(this->arrows.empty()) {
        SDL_Rect rect = {100,120,20,20};
        this->arrows.push_back(std::make_shared<ArrowButton>(&(window->getRenderer()),font,"+",rect, manager));
        rect = {100,160,20,20};
        this->arrows.push_back(std::make_shared<ArrowButton>(&(window->getRenderer()),font,"-",rect, manager));
    }
    for (auto& button: arrows) {
        button->setViewport({0,(this->window->getHeight())/2,
                    (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        button->render();
    }
    loadButtons = false;
    if (this->buttonsNPC.size() == 0)
        loadButtons = true;
    int width = 0;
    for (auto& action: information.actions){
        if (action == ActionsProfessionID::DepositGold || action == ActionsProfessionID::RetireGold) {
            if (i == 0) {
                width = 0;
            } else {
                width = 100;
            }
            if (loadButtons){
                this->buttonsNPC.push_back(createButtonAction(action,{12+width,
                    ((this->window->getHeight()-60)/2)-HEIGTHBUTTON,WIDTHBUTTON,HEIGTHBUTTON}));
            }
            this->buttonsNPC[i]->setViewport({0,(this->window->getHeight())/2,
                        (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
            this->buttonsNPC[i]->render();
            i++;
        }
    }
}   


void BankerInterface::renderItems() {
    bool loadButtons = false;
    SDL_Rect src;
    SDL_Rect dst;
    int i = 0;
    int width = 0;
    std::shared_ptr<RaisedButton> button;
    std::shared_ptr<SelectButton> selection;

    this->pagMaxInBank = information.itemsInBank.size()/ITEMSBANKER+1;

    if (this->buttonsItemsNPC.size() == 0)
        loadButtons = true;

    uint max; 
    if ((pagItemsInBank+1)*ITEMSBANKER > information.itemsInBank.size()){
        max = information.itemsInBank.size();
    } else {
        max =(pagItemsInBank+1)*ITEMSBANKER;
    }

    for (int j = pagItemsInBank*ITEMSBANKER; j < max; j++) {
        const Texture& item = manager.getTexture(information.itemsInBank[j]);
        src = {0,0,52,52};
        dst = {9+(i%3)*50,50+(i/3)*50,32,32};
        if (loadButtons) {
            selection = std::make_shared<SelectButton>(&(window->getRenderer()),dst,manager,j);
            this->buttonsItemsNPC.push_back(selection);
        }
        this->buttonsItemsNPC[i]->setViewport({0,(this->window->getHeight())/2,
                                (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->buttonsItemsNPC[i]->render();
        item.render(src,dst);
        i++;
        if (i == ITEMSBANKER)
            break;
    }
    i = 0;
    loadButtons = false;
    if (this->buttonsNPC.size() == 0)
        loadButtons = true;
    for (auto& action: information.actions){
        if (action == ActionsProfessionID::DepositItem || action == ActionsProfessionID::RetireItem) {
            if (i == 0) {
                width = 0;
            } else {
                width = 100;
            }
            if (loadButtons){
                this->buttonsNPC.push_back(createButtonAction(action,{12+width,
                    ((this->window->getHeight()-60)/2)-HEIGTHBUTTON,WIDTHBUTTON,HEIGTHBUTTON}));
            }
            this->buttonsNPC[i]->setViewport({0,(this->window->getHeight())/2,
                        (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
            this->buttonsNPC[i]->render();
            i++;
        }
    }

    if(loadButtons) {
        SDL_Rect rect = {(this->window->getWidth()/8)*2-40,((this->window->getHeight()-60)/2)-HEIGTHBUTTON*4,20,20};
        this->arrow = std::make_shared<ArrowButton>(&(window->getRenderer()),font,"+",rect, manager);
    }
    if (this->arrow != nullptr){
        this->arrow->setViewport({0,(this->window->getHeight())/2,
                    (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->arrow->render();
    }

}

void BankerInterface::render() {
    int w,h;
    int i = 0;
    int width = 0;
    int height = 0;
    SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
    SDL_Rect banker = {15,15,w,h};
    SDL_RenderCopy(&(window->getRenderer()), this->texture, NULL, &banker);
    if (this->goldValue != nullptr) {
        SDL_DestroyTexture(this->goldValue);
        this->goldValue = nullptr;
    }
    if (this->goldInBank != nullptr){
        SDL_DestroyTexture(this->goldInBank);
        this->goldInBank = nullptr;
    }
    if (pageGold) {
        renderGoldManagment();
    } else {
        renderItems();
    }
    if (this->changeScreen != nullptr){
        this->changeScreen->setViewport({0,(this->window->getHeight())/2,
                    (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->changeScreen->render();
    }
}

InputInfo BankerInterface::handleClick(int x, int y, int itemSelected) {
    InputInfo info;
    info.input  = InputID::nothing;
    bool newItemSelected = false;
    for(auto& button: buttonsItemsNPC){      
        newItemSelected = button->inside(x,y);
        if (newItemSelected) {
            if(itemSelectedNPC == -1) {
                itemSelectedNPC = button->getId() ;
            } else if (itemSelectedNPC == button->getId()) {
              itemSelectedNPC = -1;
            } else if (itemSelectedNPC != button->getId()) {
                buttonsItemsNPC[itemSelectedNPC]->onClick();
                itemSelectedNPC = button->getId();
            }
        }        
    }
    if (pageGold) {
        if (buttonsNPC[0]->inside(x,y))
            info = buttonsNPC[0]->onClick(amountGold);
        if (buttonsNPC[1]->inside(x,y))
            info = buttonsNPC[1]->onClick(amountGold);
    } else {
        if (buttonsNPC[0]->inside(x,y))
            info = buttonsNPC[0]->onClick(itemSelected);
        if (buttonsNPC[1]->inside(x,y))
            info = buttonsNPC[1]->onClick(itemSelectedNPC);
    }
   if (this->changeScreen != nullptr && this->changeScreen->inside(x,y)) {
        this->changeScreen->onClick();
        this->pageGold = !this->pageGold;
        this->buttonsItemsNPC.clear();
        this->buttonsNPC.clear();
    }
    if (this->arrows.size() != 0) {
        if (this->arrows[0]->inside(x,y)){
            this->amountGold +=10;
        }
        if (this->arrows[1]->inside(x,y)) {
            this->amountGold -=10;
            if (this->amountGold < 0)
                this->amountGold = 0;
        }
    }
    return info;
}

BankerInterface::~BankerInterface() {
    SDL_DestroyTexture(this->inBank);
}
