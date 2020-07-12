#include "Merchant.h"
#include "GameCharacter.h"

Merchant* Merchant::merchant = nullptr;

Merchant::Merchant() :items() {
    this->actions.push_back(ActionsProfessionID::Buy);
    this->actions.push_back(ActionsProfessionID::Sell);
}

Merchant* Merchant::getInstance() {
    if (merchant == nullptr)
        merchant = new Merchant();
    return merchant;
}

void Merchant::init(const std::map<ItemsInventoryID, ItemInfo>&itemsToInit) {
    for (auto &iter: itemsToInit){
        this->items.insert({iter.first, iter.second.goldCost});
    }
}

ItemsInventoryID Merchant::buyItem(ItemsInventoryID idItem, uint* balance) const {
    uint itemPrice = items.at(idItem);
    if (*balance < itemPrice)
        return ItemsInventoryID::Nothing;
    *balance -= itemPrice;
    return idItem;
}

uint Merchant::sellItem(ItemsInventoryID idItem) const {
    if (ItemsInventoryID::Nothing == idItem ) {
        return 0;
    }
    auto iter = items.find(idItem);
    return (*iter).second;
}

std::unordered_map<ItemsInventoryID,uint> Merchant::getItems() const {
    return items;
}

NPCInfo Merchant::getInfo(uint id) {
    NPCInfo info;
    info.type = 1;
    info.actions = actions;
    info.gold = 0;
    info.items = getItems();
    return info;
}

void Merchant::processInput(GameCharacter &character, InputInfo inputInfo) {
    switch (inputInfo.input) {
        case InputID::sell:
            character.gainGold(sellItem(character.removeItemFromInventory(ItemsInventoryID(inputInfo.aditional))));
            break;
        case InputID::buy:
            uint goldAmount = character.getGoldAmount();
            ItemsInventoryID aItem = buyItem(ItemsInventoryID(inputInfo.aditional), &goldAmount);
            if (aItem != ItemsInventoryID::Nothing) {
                character.addItemToInventory(aItem);
                character.setGoldAmount(goldAmount);
            }
            break;
    }
}


Merchant::~Merchant() = default;