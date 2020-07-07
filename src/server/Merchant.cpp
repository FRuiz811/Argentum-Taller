#include "Merchant.h"

Merchant* Merchant::merchant = 0;

Merchant::Merchant() :items() {
    this->actions.push_back(ActionsProfessionID::Sell);
    this->actions.push_back(ActionsProfessionID::Buy);
}

Merchant* Merchant::getInstance() {
    if (merchant == 0)
        merchant = new Merchant();
    return merchant;
}

void Merchant::init(std::unordered_map<ItemsInventoryID, ItemInfo>itemsToInit) {
    for (auto iter: itemsToInit){
        this->items.insert({iter.first, iter.second.goldCost});
    }
}

ItemsInventoryID Merchant::buyItem(ItemsInventoryID idItem, uint* balance) const {
    auto iter = items.find(idItem);
    if (*balance < (*iter).second)
        return ItemsInventoryID::Nothing;
    *balance -= (*iter).second;
    return idItem;
}

uint Merchant::sellItem(ItemsInventoryID idItem) const {
    auto iter = items.find(idItem);
    return (*iter).second;
}

const std::unordered_map<ItemsInventoryID,uint> Merchant::getItems() const {
    return std::move(items);
}

NPCInfo Merchant::getInfo(uint id) {
    NPCInfo info;
    info.type = 1;
    info.actions = actions;
    info.gold = 0;
    info.items = getItems();
    return info;
}


Merchant::~Merchant() {}