#include <iostream>
#include "UI.h"
#include "EquipButton.h"
#include "DropButton.h"
#include "UnequipButton.h"
#include "PriestInterface.h"
#include "MerchantInterface.h"
#include "BankerInterface.h"

#define WIDTHBUTTON 70
#define HEIGTHBUTTON 25
#define ITEMSMERCHANT 12
#define MERCHANTTYPE 1
#define PRIESTTYPE 2
#define BANKERTYPE 3
#define LIMITINVENTORY 9
#define TOPBARHEIGHT 60

UI::UI(Window& window, Player* player, const TextureManager& manager) : 
 playerTarget(player),window(window), manager(manager),
 font("assets/font/Prince Valiant.ttf",18,{0xA4, 0xA4, 0xA4}), texts(), info(),
 itemsID(), buttonsBuild() {
	createTexts();
    SDL_Rect buttonRect;
    for (int i = 0; i< LIMITINVENTORY; i++) {
        buttonRect = {9+(i%3)*50,50+(i/3)*50,32,32};
        std::shared_ptr<SelectButton> button = std::shared_ptr<SelectButton>(new 
            SelectButton(&(window.getRenderer()),buttonRect,manager,i));
        this->buttonsItems.push_back(button);
    }
    std::shared_ptr<RaisedButton> equipButton = std::shared_ptr<RaisedButton>(new EquipButton(&(window.getRenderer()),font,
        "Equipar",{9,205,WIDTHBUTTON,HEIGTHBUTTON}, manager,playerTarget));
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
    int mana = playerMaxMana > 0 ? (playerMana * (widthSegment-2))/playerMaxMana : 0;
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
    int exp = ((playerExp-this->maxExpPreviousLevel) * (widthSegment-2))/(playerMaxExp-this->maxExpPreviousLevel);
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

    if (this->maxExpActualLevel != playerMaxExp) {
        this->maxExpPreviousLevel = this->maxExpActualLevel;
        this->maxExpActualLevel = playerMaxExp;
    }

}

void UI::deleteInfo(){
    for (auto& text: info) {
        font.deleteText(text);
        this->info.pop_back();
    }
}

void UI::updateStates() {
    const Texture& topBar = manager.getTexture(TextureID::TopBar);
    SDL_Rect topBarViewport = {0,0,this->window.getWidth(),TOPBARHEIGHT};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &topBarViewport);
    SDL_RenderCopy(&(this->window.getRenderer()), topBar.getTexture(), NULL, NULL);
    deleteInfo();
    updateHealth();
    updateMana();
    updateGold();
    updateLevelAndExpirience();
}

void UI::updateItems() {
    itemsID.clear();
    int w,h;
    SDL_QueryTexture(this->texts[4], NULL, NULL, &w, &h);
    SDL_Rect invText = {15,15,w,h};
    SDL_RenderCopy(&(window.getRenderer()), this->texts[4], NULL, &invText);

    std::string items = this->playerTarget->getInventory();
    std::string item;
    int idItem;

    SDL_Rect src = {0,0,52,52};
    SDL_Rect dst;
    for (int i = 0; i < LIMITINVENTORY; i++) {
        item = items.substr(2*i+i,2);
        idItem = std::stoi(item);
        const Texture& item = manager.getTexture((ItemsInventoryID)idItem);
        itemsID.push_back((ItemsInventoryID)idItem);

        buttonsItems[i]->setViewport({0,TOPBARHEIGHT,widthSegment*2,(this->window.getHeight()-TOPBARHEIGHT)/2});
        dst = {35+(i%3)*widthSegment/2,50+(i/3)*((this->window.getHeight()-TOPBARHEIGHT)/2)/5,widthSegment/3,widthSegment/3};
        buttonsItems[i]->updatePosition(dst);
        if (idItem > 0) {
            buttonsItems[i]->render();
        }
        item.render(src,dst);
    }   
}

void UI::updateInventory() {
    const Texture& statBackground = manager.getTexture(TextureID::StatsBackground);
    SDL_Rect inventoryViewPort = {0,TOPBARHEIGHT,widthSegment*2,(this->window.getHeight()-TOPBARHEIGHT)/2};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &inventoryViewPort);
    SDL_Rect dst = {0,0,widthSegment*2,(this->window.getHeight()-TOPBARHEIGHT)/2};
    SDL_RenderCopy(&(this->window.getRenderer()), statBackground.getTexture(), NULL, &dst);
    updateItems();
    int i = 0;
    for (auto& button: buttonsInventory){
        button->setViewport({0,TOPBARHEIGHT,widthSegment*2,(this->window.getHeight()-TOPBARHEIGHT)/2});
        button->updatePosition({20+(i%2)*widthSegment,int(((this->window.getHeight()-TOPBARHEIGHT)/2)-HEIGTHBUTTON*2.5),WIDTHBUTTON,HEIGTHBUTTON});
        button->render();
        i++;
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

    if (this->buttonsBuild.size() == 0) {
        std::shared_ptr<SelectButton> button;
        button = std::shared_ptr<SelectButton>(new SelectButton(
            &(window.getRenderer()),{widthSegment-widthSegment/6,50,widthSegment/3,widthSegment/3},manager,0));
        this->buttonsBuild.push_back(button);
        button = std::shared_ptr<SelectButton>(new SelectButton(
            &(window.getRenderer()),{widthSegment-(widthSegment/3)*2,140,widthSegment/3,widthSegment/3},manager,1));
        this->buttonsBuild.push_back(button);
        button = std::shared_ptr<SelectButton>(new SelectButton(
            &(window.getRenderer()),{widthSegment+widthSegment/3,140,widthSegment/3,widthSegment/3},manager,2));
        this->buttonsBuild.push_back(button);
        this->unequipButton = std::shared_ptr<RaisedButton> (new UnequipButton(
            &(window.getRenderer()),font,"Guardar",{9,205,WIDTHBUTTON,HEIGTHBUTTON}, manager,playerTarget));
    }

    for(uint i = 0; i < this->buttonsBuild.size(); i++){
        buttonsBuild[i]->setViewport({0,(this->window.getHeight())/2,widthSegment*2,
                            (this->window.getHeight())/2});
        if (i == 0) {
            buttonsBuild[i]->updatePosition({widthSegment-widthSegment/6,50,widthSegment/3,widthSegment/3});
        } else if (i == 1) {
            buttonsBuild[i]->updatePosition({widthSegment-(widthSegment/3)*2,140,widthSegment/3,widthSegment/3});
        } else if (i == 2) {
            buttonsBuild[i]->updatePosition({widthSegment+widthSegment/3,140,widthSegment/3,widthSegment/3});
        }
        buttonsBuild[i]->render();
    }

    SDL_Rect src = {0,0,52,52};
    itemHelmet.render(src,{widthSegment-widthSegment/6,50,widthSegment/3,widthSegment/3});
    itemBody.render(src,{widthSegment-widthSegment/3,117+widthSegment/5,(widthSegment/3)*2,(widthSegment/3)*2});
    if (this->playerTarget->getHealth() == 0) {
        itemHead.render({0,0,52,52},{widthSegment-widthSegment/6,85+widthSegment/6,widthSegment/3,widthSegment/3});
    } else {
        itemHead.render({0,0,17,17},{widthSegment-widthSegment/6,85+widthSegment/6,widthSegment/3,widthSegment/3});
    }
    itemWeapon.render(src,{widthSegment-(widthSegment/3)*2,140,widthSegment/3,widthSegment/3});
    itemShield.render(src,{widthSegment+widthSegment/3,140,widthSegment/3,widthSegment/3});

    this->unequipButton->setViewport({0,(this->window.getHeight())/2,widthSegment*2,
                            (this->window.getHeight())/2});
    this->unequipButton->updatePosition({20,int(((this->window.getHeight())/2)-HEIGTHBUTTON*2.5),WIDTHBUTTON,HEIGTHBUTTON});
    this->unequipButton->render();

}

void UI::updateInteract() {
    if (this->npc == nullptr) {
        if (this->informationNPC.type == MERCHANTTYPE) {
            this->npc = std::shared_ptr<NPCInterface>(new MerchantInterface(informationNPC,&window,manager,playerTarget));
        } else if (this->informationNPC.type == PRIESTTYPE) {
            this->npc = std::shared_ptr<NPCInterface>(new PriestInterface(informationNPC,&window,manager,playerTarget));
        } else if (this->informationNPC.type == BANKERTYPE) {
            this->npc = std::shared_ptr<NPCInterface>(new BankerInterface(informationNPC,&window,manager,playerTarget));
        } else {
            updateBuild();
        }
    } else {
        npc->update(this->informationNPC);
    }
    if (this->npc != nullptr)
        this->npc->render(); 
}

void UI::updateEquipment() {
    const Texture& statBackground = manager.getTexture(TextureID::StatsBackground);
    SDL_Rect equipmentViewPort = {0,(this->window.getHeight())/2,widthSegment*2,(this->window.getHeight())/2};
    SDL_RenderSetViewport(&(this->window.getRenderer()), &equipmentViewPort);
    SDL_Rect dst = {0,0,widthSegment*2,(this->window.getHeight())/2};
    SDL_RenderCopy(&(this->window.getRenderer()), statBackground.getTexture(), NULL, &dst);
    if (this->playerTarget->getState() == CharacterStateID::Interact) {
        updateInteract();
        this->buttonsBuild.clear();
        this->unequipButton = nullptr;
        this->buildSelected = -1;
    } else {
        this->npc = nullptr;
        this->informationNPC.type = 0;
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
                if (button->inside(x,y) && itemSelected != -1) 
                    info = button->onClick(itemSelected+1);
            }
            for(auto& button: buttonsBuild){      
                newItemSelected = button->inside(x,y);
                if (newItemSelected) {
                    if(buildSelected == -1) {
                        buildSelected = button->getId();
                    } else if (buildSelected == button->getId()) {
                        buildSelected = -1;
                    } else if (buildSelected != button->getId()) {
                        buttonsBuild[buildSelected]->onClick();
                        buildSelected = button->getId();
                    }
                }        
            }   

            if (this->npc != nullptr) {
                int itemId = 0;
                if (itemSelected != -1)
                    itemId = int(itemsID[itemSelected]);
                info = this->npc->handleClick(x,y,itemId);
            } else if (this->unequipButton != nullptr) {
                if (this->unequipButton->inside(x,y) && buildSelected > -1)
                    info = this->unequipButton->onClick(buildSelected);
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
}

UI::~UI() {
    for (auto& text: texts) {
        font.deleteText(text);
    }
}