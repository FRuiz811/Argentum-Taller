#include <iostream>
#include "UI.h"
#include "EquipButton.h"
#include "DropButton.h"
#include "ResurrectButton.h"
#include "CureButton.h"
#include "BuyButton.h"
#include "SellButton.h"

#define WIDTHBUTTON 70
#define HEIGTHBUTTON 25

UI::UI(Window& window, Player* player, const TextureManager& manager) : 
window(window), playerTarget(player), manager(manager),
 font("assets/font/Prince Valiant.ttf",18,{0xA4, 0xA4, 0xA4}), texts(),
 buttonsNPC(),buttonsItemsNPC() {
	createTexts();
    SDL_Rect buttonRect;
    for (int i = 0; i<9; i++) {
        buttonRect = {9+(i%3)*50,50+(i/3)*50,32,32};
        std::shared_ptr<SelectButton> button = std::shared_ptr<SelectButton>(new 
            SelectButton(&(window.getRenderer()),buttonRect,manager,i));
        this->buttonsItems.push_back(button);
    }
    std::shared_ptr<RaisedButton> equipButton = std::shared_ptr<RaisedButton>(new 
        EquipButton(&(window.getRenderer()),font,"Equipar",{9,205,70,HEIGTHBUTTON}, manager,playerTarget));
    std::shared_ptr<RaisedButton> dropButton = std::shared_ptr<RaisedButton>(new 
        DropButton(&(window.getRenderer()),font,"Tirar",{109,205,WIDTHBUTTON,HEIGTHBUTTON}, manager,playerTarget));
    this->buttonsInventory.push_back(equipButton);
    this->buttonsInventory.push_back(dropButton);
    this->informationNPC.type = 0;
}

void UI::updateHealth(){
    int w, h,width_text,height_text;
    SDL_QueryTexture(this->texts[0], NULL, NULL, &w, &h);

    int playerHealth = this->playerTarget->getHealth();
    int playerMaxHealth = this->playerTarget->getMaxHealth();
    int health = (playerHealth * (widthSegment-2))/playerMaxHealth;
    std::string life = "("+ std::to_string(playerHealth) + "/" + std::to_string(playerMaxHealth) + ")";
    SDL_Texture* lifeTexture = font.createText(life,&(window.getRenderer()), &width_text, &height_text);
    this->info.push_back(lifeTexture);

    SDL_Rect healthText = {9+widthSegment*0,10,w,h};
    SDL_Rect lifeRect = {12+widthSegment*0+w,10,width_text,height_text};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[0], NULL, &healthText);
    SDL_RenderCopy(&(window.getRenderer()), this->info[0],NULL,&lifeRect);

    SDL_Rect healthRect = {9+widthSegment*0,30,widthSegment,20};
    SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0xA4, 0xA4, 0xA4, 0xAA);		
	SDL_RenderDrawRect(&(this->window.getRenderer()), &healthRect);

    SDL_Rect fillHealth = {10+widthSegment*0,31, health,18};
	SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0xFF, 0x00, 0x00, 0xFF);		
	SDL_RenderFillRect(&(this->window.getRenderer()), &fillHealth);
}

void UI::updateMana(){
    int w, h,width_text,height_text;
    SDL_QueryTexture(this->texts[1], NULL, NULL, &w, &h);

    int playerMana = this->playerTarget->getMana();
    int playerMaxMana = this->playerTarget->getMaxMana();
    int mana = (playerMana * (widthSegment-2))/playerMaxMana;
    std::string manaTotal = "("+ std::to_string(playerMana) + "/" + std::to_string(playerMaxMana) + ")";
    SDL_Texture* manaTexture = font.createText(manaTotal,&(window.getRenderer()), &width_text, &height_text);
    this->info.push_back(manaTexture);

    SDL_Rect manaText = {9+widthSegment*2,10,w,h};
    SDL_Rect manaTotalRect = {12+widthSegment*2+w,10,width_text,height_text};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[1], NULL, &manaText);
    SDL_RenderCopy(&(window.getRenderer()), this->info[1],NULL,&manaTotalRect);

    SDL_Rect manaRect = {9+widthSegment*2,30,widthSegment,20};
    SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0xA4, 0xA4, 0xA4, 0xAA);		
	SDL_RenderDrawRect(&(this->window.getRenderer()), &manaRect);

    SDL_Rect fillMana = {10+widthSegment*2,31, mana,18};
	SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0x01, 0xDF, 0xD7, 0xFF);		
	SDL_RenderFillRect(&(this->window.getRenderer()), &fillMana);
}

void UI::updateGold() {
    int width_text,height_text;
    const Texture& goldTexture = manager.getTexture(TextureID::Gold);

    int safeGold = this->playerTarget->getSafeGold();
    int actualGold = this->playerTarget->getGold();
    std::string gold = std::to_string(actualGold) + "/" + std::to_string(safeGold);
    SDL_Texture* goldText = font.createText(gold,&(window.getRenderer()), &width_text, &height_text);
    this->info.push_back(goldText);

    SDL_Rect srcGold = {0,0,32,32};
    SDL_Rect dstGold = {widthSegment*4,10,32,32};
    goldTexture.render(srcGold,dstGold);

    SDL_Rect goldRect = {36+widthSegment*4,10,width_text,height_text};
    SDL_RenderCopy(&(window.getRenderer()), this->info[2],NULL,&goldRect);
}

void UI::updateLevelAndExpirience() {
    int w, h,width_text,height_text;
    SDL_QueryTexture(this->texts[2], NULL, NULL, &w, &h);

    const Texture& star = manager.getTexture(TextureID::Star);
    SDL_Rect srcStar = {0,0,15,16};
    SDL_Rect dstStar = {20+widthSegment*5,15,15,16};
    star.render(srcStar,dstStar);

    std::string level = std::to_string(this->playerTarget->getLevel());
    SDL_Texture* levelTexture = font.createText(level,&(window.getRenderer()), &width_text, &height_text);
    this->info.push_back(levelTexture);

    SDL_Rect levelText = {50+widthSegment*5,10,w,h};
    SDL_Rect levelRect = {50+w+widthSegment*5,10,width_text,height_text};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[2], NULL, &levelText);
    SDL_RenderCopy(&(window.getRenderer()), this->info[3],NULL,&levelRect);

    int playerExp = this->playerTarget->getExp();
    int playerMaxExp = this->playerTarget->getMaxExp();
    int exp = (playerExp * (widthSegment-2))/playerMaxExp;
    std::string expTotal = "("+ std::to_string(playerExp) + "/" + std::to_string(playerMaxExp) + ")";
    SDL_Texture* expTexture = font.createText(expTotal,&(window.getRenderer()), &width_text, &height_text);
    this->info.push_back(expTexture);

    SDL_QueryTexture(this->texts[3], NULL, NULL, &w, &h);
    SDL_Rect expText = {25+widthSegment*6,8,w,h};
    SDL_Rect expTotalRect = {25+widthSegment*6+w,8,width_text,height_text};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[3], NULL, &expText);
    SDL_RenderCopy(&(window.getRenderer()), this->info[4],NULL,&expTotalRect);

    SDL_Rect expRect = {25+widthSegment*6,30,widthSegment,20};
    SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0xA4, 0xA4, 0xA4, 0xAA);		
	SDL_RenderDrawRect(&(this->window.getRenderer()), &expRect);

    SDL_Rect fillExp = {26+widthSegment*6,31, exp,18};
	SDL_SetRenderDrawColor(&(this->window.getRenderer()), 0x00, 0xFF, 0x00, 0xFF);		
	SDL_RenderFillRect(&(this->window.getRenderer()), &fillExp);

}

void UI::deleteInfo(){
    for (auto& text: info) {
        font.deleteText(text);
        this->info.pop_back();
    }
}

void UI::updateStates() {
    const Texture& topBar = manager.getTexture(TextureID::TopBar);
    SDL_Rect topBarViewport = {0,0,this->window.getWidth(),60};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &topBarViewport);
    SDL_RenderCopy(&(this->window.getRenderer()), topBar.getTexture(), NULL, NULL);
    deleteInfo();
    updateHealth();
    updateMana();
    updateGold();
    updateLevelAndExpirience();
}

void UI::updateItems() {
    int w,h;
    SDL_QueryTexture(this->texts[4], NULL, NULL, &w, &h);
    SDL_Rect invText = {15,15,w,h};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[4], NULL, &invText);

    std::string items = this->playerTarget->getInventory();
    std::string item;
    int idItem;

    SDL_Rect src = {0,0,52,52};
    SDL_Rect dst;
    for (int i = 0; i<9; i++) {
        item = items.substr(2*i+i,2);
        idItem = std::stoi(item);
        const Texture& item = manager.getTexture((ItemsInventoryID)idItem);
        buttonsItems[i]->setViewport({0,60,widthSegment*2,(this->window.getHeight()-60)/2});
        if (idItem > 0) {
            buttonsItems[i]->render();
        }
        dst = {9+(i%3)*50,50+(i/3)*50,32,32};
        item.render(src,dst);
    }   
}

void UI::updateInventory() {
    const Texture& statBackground = manager.getTexture(TextureID::StatsBackground);
    SDL_Rect inventoryViewPort = {0,60,widthSegment*2,(this->window.getHeight()-60)/2};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &inventoryViewPort);
    SDL_Rect dst = {0,0,widthSegment*2,(this->window.getHeight()-60)/2};
    SDL_RenderCopy(&(this->window.getRenderer()), statBackground.getTexture(), NULL, &dst);
    updateItems();
    for (auto& button: buttonsInventory){
        button->setViewport({0,60,widthSegment*2,(this->window.getHeight()-60)/2});
        button->render();
    }
}

void UI::updateBuild() {
    int w,h;
    SDL_QueryTexture(this->texts[5], NULL, NULL, &w, &h);
    SDL_Rect equipment = {15,15,w,h};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[5], NULL, &equipment);
    PlayerInfo info = this->playerTarget->getInfo();
    const Texture& itemBody = manager.getTexture(info.getBodyID());
    const Texture& itemHead = manager.getTexture(info.getHeadID());
    const Texture& itemHelmet = manager.getTexture(info.getHelmetID());
    const Texture& itemWeapon = manager.getTexture(info.getWeaponID());
    const Texture& itemShield = manager.getTexture(info.getShieldID());
    SDL_Rect src = {0,0,52,52};
    itemHelmet.render(src,{widthSegment-16,50,32,32});
    if (this->playerTarget->getState() == CharacterStateID::Dead){
        itemHead.render({0,0,52,52},{widthSegment-16,85,32,32});
    } else {
        itemHead.render({0,0,17,17},{widthSegment-16,85,32,32});
    }
    itemBody.render(src,{widthSegment-32,117,64,64});
    itemWeapon.render(src,{widthSegment-64,130,32,32});
    itemShield.render(src,{widthSegment+32,130,32,32});
}

void UI::generatePriest() {
    int w,h;
    int i = 0;
    int width = 0;
    int height = 0;
    SDL_QueryTexture(this->texts[8], NULL, NULL, &w, &h);
    SDL_Rect priest = {15,15,w,h};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[8], NULL, &priest);

    SDL_Rect src;
    SDL_Rect dst;
    std::shared_ptr<RaisedButton> button;
    std::shared_ptr<SelectButton> selection;
    SDL_Texture* textureGold;
    bool loadButtons = false;
    if (this->buttonsItemsNPC.size() == 0)
        loadButtons = true;
    for (auto& iter: this->informationNPC.items) {
        const Texture& item = manager.getTexture(iter.first);
        src = {0,0,52,52};
        dst = {9+(i%3)*50,50+(i/3)*50,32,32};
        if (loadButtons) {
            selection = std::shared_ptr<SelectButton>(new 
            SelectButton(&(window.getRenderer()),dst,manager,i));
            this->buttonsItemsNPC.push_back(selection);
        }
        this->buttonsItemsNPC[i]->setViewport({0,(this->window.getHeight())/2,widthSegment*2,(this->window.getHeight())/2});
        this->buttonsItemsNPC[i]->render();
        item.render(src,dst);
        textureGold = font.createText(std::to_string(iter.second),&(window.getRenderer()),&w,&h);
        this->gold.push_back(textureGold);
        src = {0,0,w,h};
        dst = {20+(i%3)*50, 65+(i/3)*50,w,h};
        SDL_RenderCopy(&(window.getRenderer()),textureGold,&src,&dst);
        i++;
    }
    i = 0;
    loadButtons = false;
    if (this->buttonsNPC.size() == 0)
        loadButtons = true;
    for (auto& action: this->informationNPC.actions) {
        if (i % 2 == 0) {
            width = 0;
        } else {
            width = 100;
        }
        if (i < this->informationNPC.actions.size()/2.0) {
            height = 0;
        } else {
            height = 50;
        }
        if (loadButtons){
            button = createButtonAction(action,{12+width,((this->window.getHeight()-60)/2)-height-HEIGTHBUTTON,WIDTHBUTTON,HEIGTHBUTTON});
            this->buttonsNPC.push_back(button);
        }
        this->buttonsNPC[i]->setViewport({0,(this->window.getHeight())/2,widthSegment*2,(this->window.getHeight())/2});
        this->buttonsNPC[i]->render();
        i++;
    }

}

void UI::updateInteract() {
    if (this->informationNPC.type == 1) {
        //generateMerchant();
    } else if (this->informationNPC.type == 2) {
        generatePriest();
    } else if (this->informationNPC.type == 3) {
        //generateBanker();
    } else {
        updateBuild();
    }
}

void UI::updateEquipment() {
    const Texture& statBackground = manager.getTexture(TextureID::StatsBackground);
    SDL_Rect equipmentViewPort = {0,(this->window.getHeight())/2,widthSegment*2,(this->window.getHeight())/2};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &equipmentViewPort);
    SDL_Rect dst = {0,0,widthSegment*2,(this->window.getHeight())/2};
    SDL_RenderCopy(&(this->window.getRenderer()), statBackground.getTexture(), NULL, &dst);
    if (this->playerTarget->getState() == CharacterStateID::Interact) {
        updateInteract();
    } else {
        this->buttonsItemsNPC.clear();
        this->buttonsNPC.clear();
        deleteGoldValues();
        updateBuild();
    }
}

void UI::render() {
    this->widthSegment = this->window.getWidth()/8;
    updateInventory();
    updateEquipment();
    updateStates();
}

void UI::setNPCInfo(NPCInfo info) {
    this->informationNPC = info;
}

InputInfo UI::handleClick(SDL_Event& event) {
    int x,y;
    InputInfo info;
    info.input  = InputID::nothing;
    bool newItemSelected = false;
    if (event.type == SDL_MOUSEMOTION || event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
        SDL_GetMouseState(&x, &y);
    switch(event.type) {
        case SDL_MOUSEBUTTONDOWN:
            for(auto& button: buttonsItems){      
                newItemSelected = button->inside(x,y);
                if (newItemSelected) {
                    if(itemSelected == -1) {
                        itemSelected = button->getId();
                    } else if (itemSelected == button->getId()) {
                        itemSelected = -1;
                    } else if (itemSelected != button->getId()) {
                        buttonsItems[itemSelected]->onClick();
                        itemSelected = button->getId();
                    }
                }        
            }
            for (auto& button: buttonsInventory) {
                if (button->inside(x,y))
                    info = button->onClick(itemSelected+1);
            }
            for(auto& button: buttonsItemsNPC){      
                newItemSelected = button->inside(x,y);
                if (newItemSelected) {
                    if(itemSelectedNPC == -1) {
                        itemSelectedNPC = button->getId();
                    } else if (itemSelectedNPC == button->getId()) {
                        itemSelectedNPC = -1;
                    } else if (itemSelectedNPC != button->getId()) {
                        buttonsItemsNPC[itemSelectedNPC]->onClick();
                        itemSelectedNPC = button->getId();
                    }
                }        
            }
            for (auto& button: buttonsNPC) {
                if (button->inside(x,y))
                    info = button->onClick(itemSelectedNPC+1);
            }
            break;
    }
    return info;
}

void UI::createTexts() {
    int width_text, height_text;
    SDL_Texture* health = font.createText("Vida",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(health);
    SDL_Texture* mana = font.createText("Mana",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(mana);
    SDL_Texture* level = font.createText("Nivel ",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(level);
    SDL_Texture* expirience = font.createText("Experiencia",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(expirience);
    SDL_Texture* inventory = font.createText("Inventario",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(inventory);
    SDL_Texture* equipment = font.createText("Equipacion",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(equipment);
    SDL_Texture* banker = font.createText("Banquero",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(banker);
    SDL_Texture* merchant = font.createText("Comerciante",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(merchant);
    SDL_Texture* priest = font.createText("Sacerdote",
        &(window.getRenderer()), &width_text, &height_text);
    this->texts.push_back(priest);
}


std::shared_ptr<RaisedButton> UI::createButtonAction(ActionsProfessionID action,SDL_Rect rect) {
    std::string text;
    std::shared_ptr<RaisedButton> button;
    switch (action) {
    case ActionsProfessionID::Buy:
        text = "Comprar";
        button = std::shared_ptr<RaisedButton>(new BuyButton(&(window.getRenderer()),font,text,rect, manager,playerTarget));
        break;
    case ActionsProfessionID::Sell:
        text = "Vender";
        button = std::shared_ptr<RaisedButton>(new SellButton(&(window.getRenderer()),font,text,rect, manager,playerTarget));
        break;
    case ActionsProfessionID::Resurrect:
        text = "Resucitar";
        button = std::shared_ptr<RaisedButton>(new ResurrectButton(&(window.getRenderer()),font,text,rect, manager,playerTarget));
        break;
    case ActionsProfessionID::Cure:
        text = "Curar";
        button = std::shared_ptr<RaisedButton>(new CureButton(&(window.getRenderer()),font,text,rect, manager,playerTarget));
        break;
    /*case ActionsProfessionID::DepositGold:
        text ="Depositar Oro";
        break;
    case ActionsProfessionID::DepositItem:
        text = "Depositar Item";
        break;
    case ActionsProfessionID::RetireItem:
        text = "Retirar Item";
        break;
    case ActionsProfessionID::RetireGold:
        text = "Retirar Oro";
        break;*/
    }
    return button;
}

void UI::deleteGoldValues() {
    std::vector<SDL_Texture*>::iterator iter;
    iter = this->gold.begin();
    while (iter != this->gold.end()) {
        SDL_DestroyTexture(*iter);
        iter  = gold.erase(iter);
    }
}

UI::~UI() {
    for (auto& text: texts) {
        font.deleteText(text);
    }
}