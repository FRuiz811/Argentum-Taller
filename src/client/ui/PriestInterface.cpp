#include "PriestInterface.h"

#include <memory>

#define WIDTHBUTTON 70
#define HEIGTHBUTTON 25

PriestInterface::PriestInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player) : 
    NPCInterface(info,window,manager,player), buttonsItemsNPC(), buttonsNPC(), gold() {
    int width_text, height_text;
    SDL_Texture* priest = font.createText("Sacerdote",
        &(window->getRenderer()), &width_text, &height_text);
    this->texture = priest;
}

void PriestInterface::render() {
    int w,h;
    int i = 0;
    int width = 0;
    int height = 0;
    SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
    SDL_Rect priest = {15,15,w,h};
    SDL_RenderCopy(&(window->getRenderer()), this->texture, NULL, &priest);

    SDL_Rect src;
    SDL_Rect dst;
    std::shared_ptr<RaisedButton> button;
    std::shared_ptr<SelectButton> selection;
    SDL_Texture* textureGold;
    bool loadButtons = false;
    if (this->buttonsItemsNPC.size() == 0)
        loadButtons = true;
    for (auto& iter: this->information.items) {
        const Texture& item = manager.getTexture(iter.first);
        src = {0,0,52,52};
        dst = {9+(i%3)*50,50+(i/3)*50,32,32};
        if (loadButtons) {
            selection = std::make_shared<SelectButton>(&(window->getRenderer()),dst,manager, (int)iter.first);
            this->buttonsItemsNPC.push_back(selection);
        }
        this->buttonsItemsNPC[i]->setViewport({0,(this->window->getHeight())/2,(this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->buttonsItemsNPC[i]->render();
        item.render(src,dst);
        textureGold = font.createText(std::to_string(iter.second),&(window->getRenderer()),&w,&h);
        this->gold.push_back(textureGold);
        src = {0,0,w,h};
        dst = {20+(i%3)*50, 65+(i/3)*50,w,h};
        SDL_RenderCopy(&(window->getRenderer()),textureGold,&src,&dst);
        i++;
    }
    i = 0;
    loadButtons = false;
    if (this->buttonsNPC.size() == 0)
        loadButtons = true;
    for (auto& action: this->information.actions) {
        if (i % 2 == 0) {
            width = 0;
        } else {
            width = 100;
        }
        if (i < this->information.actions.size()/2.0) {
            height = 0;
        } else {
            height = 50;
        }
        if (loadButtons){
            button = createButtonAction(action,{12+width,((this->window->getHeight()-60)/2)-height-HEIGTHBUTTON,WIDTHBUTTON,HEIGTHBUTTON});
            this->buttonsNPC.push_back(button);
        }
        this->buttonsNPC[i]->setViewport({0,(this->window->getHeight())/2,(this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->buttonsNPC[i]->render();
        i++;
    }
}

InputInfo PriestInterface::handleClick(int x, int y, int itemSelected) {
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
    for (auto& button: buttonsNPC) {
        if (button->inside(x,y))
            info = button->onClick(itemSelectedNPC+1);
        }
    return info;
}

void PriestInterface::deleteGoldValues() {
    std::vector<SDL_Texture*>::iterator iter;
    iter = this->gold.begin();
    while (iter != this->gold.end()) {
        SDL_DestroyTexture(*iter);
        iter  = gold.erase(iter);
    }
}


PriestInterface::~PriestInterface() {
    deleteGoldValues();
}
