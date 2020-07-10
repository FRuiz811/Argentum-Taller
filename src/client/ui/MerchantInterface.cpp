#include "MerchantInterface.h"

#define WIDTHBUTTON 70
#define HEIGTHBUTTON 25
#define ITEMSMERCHANT 12

MerchantInterface::MerchantInterface(NPCInfo info,Window* window, const TextureManager& manager,Player* player) : 
    NPCInterface(info,window,manager,player), buttonsItemsNPC(), buttonsNPC(), gold() {
    int width_text, height_text;
    SDL_Texture* merchant = font.createText("Comerciante",
        &(window->getRenderer()), &width_text, &height_text);
    this->texture = merchant;
}

void MerchantInterface::render() {
    int w,h;
    int i = 0;
    int width = 0;
    SDL_QueryTexture(this->texture, NULL, NULL, &w, &h);
    SDL_Rect merchant = {15,15,w,h};
    SDL_RenderCopy(&(window->getRenderer()), this->texture, NULL, &merchant);

    SDL_Rect src;
    SDL_Rect dst;
    std::shared_ptr<RaisedButton> button;
    std::shared_ptr<SelectButton> selection;
    SDL_Texture* textureGold;
    bool loadButtons = false;

    this->pagMax = information.items.size()/ITEMSMERCHANT+1;
    std::vector<std::pair<ItemsInventoryID,uint>> items(information.items.begin(),information.items.end());

    if (this->buttonsItemsNPC.size() == 0)
        loadButtons = true;

    uint max; 
    if ((pagItems+1)*ITEMSMERCHANT > information.items.size()){
        max = information.items.size();
    } else {
        max =(pagItems+1)*ITEMSMERCHANT;
    }

    for (int j = pagItems*ITEMSMERCHANT; j < max; j++) {
        const Texture& item = manager.getTexture(items[j].first);
        src = {0,0,52,52};
        dst = {9+(i%3)*50,50+(i/3)*50,32,32};
        if (loadButtons) {
            selection = std::shared_ptr<SelectButton>(new 
            SelectButton(&(window->getRenderer()),dst,manager,i));
            this->buttonsItemsNPC.push_back(selection);
        }
        this->buttonsItemsNPC[i]->setViewport({0,(this->window->getHeight())/2,
                                (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->buttonsItemsNPC[i]->render();
        item.render(src,dst);
        textureGold = font.createText(std::to_string(items[j].second),&(window->getRenderer()),&w,&h);
        this->gold.push_back(textureGold);
        src = {0,0,w,h};
        dst = {20+(i%3)*50, 65+(i/3)*50,w,h};
        SDL_RenderCopy(&(window->getRenderer()),textureGold,&src,&dst);
        i++;
        if (i == ITEMSMERCHANT)
            break;
    }
    i = 0;

    loadButtons = false;
    if (this->buttonsNPC.size() == 0)
        loadButtons = true;
    for (auto& action: this->information.actions) {
        if (i == 0) {
            width = 0;
        } else {
            width = 100;
        }
        if (loadButtons){
            button = createButtonAction(action,{12+width,
                    ((this->window->getHeight()-60)/2)-HEIGTHBUTTON,WIDTHBUTTON,HEIGTHBUTTON});
            this->buttonsNPC.push_back(button);
        }
        this->buttonsNPC[i]->setViewport({0,(this->window->getHeight())/2,
                        (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->buttonsNPC[i]->render();
        i++;
    }
    if(loadButtons) {
        SDL_Rect rect = {(this->window->getWidth()/8)*2-40,((this->window->getHeight()-60)/2)-HEIGTHBUTTON*4,20,20};
        this->arrow = std::shared_ptr<ArrowButton>(new ArrowButton(&(window->getRenderer()),font,"+",rect, manager));
    }
    if (this->arrow != nullptr){
        this->arrow->setViewport({0,(this->window->getHeight())/2,
                    (this->window->getWidth()/8)*2,(this->window->getHeight())/2});
        this->arrow->render();
    }
}

InputInfo MerchantInterface::handleClick(int x, int y, int itemSelected) {
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
    if (buttonsNPC[0]->inside(x,y))
        info = buttonsNPC[0]->onClick(itemSelectedNPC+1);
    if (buttonsNPC[1]->inside(x,y))
        info = buttonsNPC[1]->onClick(itemSelected+1);

    if (this->arrow != nullptr && this->arrow->inside(x,y)) {
        this->arrow->onClick();
        this->pagItems = (pagItems+1) % this->pagMax;
    }
    return info;
}

void MerchantInterface::deleteGoldValues() {
    std::vector<SDL_Texture*>::iterator iter;
    iter = this->gold.begin();
    while (iter != this->gold.end()) {
        SDL_DestroyTexture(*iter);
        iter  = gold.erase(iter);
    }
}


MerchantInterface::~MerchantInterface() {
    deleteGoldValues();
}
