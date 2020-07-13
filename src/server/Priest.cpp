#include "Priest.h"

Priest* Priest::priest = nullptr;

Priest::Priest() :items() {
    this->actions.push_back(ActionsProfessionID::Cure);
    this->actions.push_back(ActionsProfessionID::Resurrect);
    this->actions.push_back(ActionsProfessionID::Buy);
}


Priest* Priest::getInstance() {
    if (priest == nullptr)
        priest = new Priest();
    return priest;
}

void Priest::init(const std::map<ItemsInventoryID, ItemInfo>&itemsToInit) {
    for (auto &iter: itemsToInit){
        if(iter.second.type == "Potion")
            this->items.insert({iter.first, iter.second.goldCost});
    }
}


ItemsInventoryID Priest::buyItem(ItemsInventoryID idItem, uint* balance) const {
    auto iter = items.find(idItem);
    if (*balance < (*iter).second)
        return ItemsInventoryID::Nothing;
    *balance -= (*iter).second;
    return idItem;
}

std::unordered_map<ItemsInventoryID,uint> Priest::getItems() const {
    return items;
}

NPCInfo Priest::getInfo(uint id) {
    NPCInfo info;
    info.type = 2;
    info.actions = actions;
    info.gold = 0;
    info.items = getItems();
    return info;
}

void Priest::processInput(GameCharacter &character, InputInfo inputInfo) {
    uint sell,goldAmount;
        switch (inputInfo.input) {
        case InputID::buy:
            goldAmount = character.getGoldAmount();
            if (!character.inventoryIsFull()) {
                ItemsInventoryID aItem = buyItem(ItemsInventoryID(inputInfo.aditional), &goldAmount);
                if (aItem != ItemsInventoryID::Nothing) {
                    character.addItemToInventory(aItem);
                    character.setGoldAmount(goldAmount);
                }
            }
            break;
        case InputID::resurrect:
            if (character.isDead())
                character.cure();
            break;
        case InputID::cure:
            character.cure();
        }
}

Priest::~Priest() = default;
