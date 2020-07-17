#include "Inventory.h"

#include <utility>
#include <algorithm>
#include "GameStatsConfig.h"

Inventory::Inventory() :
inventoryItems(), itemsAmount(0),
limit(GameStatsConfig::getInventoryLimit()){
    for (int i = 0; i < limit; ++i){
        inventoryItems.push_back(ItemsInventoryID::Nothing);
    }
}

ItemsInventoryID Inventory::getItem(int index) const {
    return inventoryItems.at(index);
}

bool Inventory::addItem(ItemsInventoryID aItemInventoryId) {
    bool added = false;
    if (!isFull() && aItemInventoryId != ItemsInventoryID::Nothing) {
        auto iter = std::find(inventoryItems.begin(), inventoryItems.end(), ItemsInventoryID::Nothing);
        (*iter) = aItemInventoryId;
        itemsAmount++;
        added = true;
    }
    return added;
}

bool Inventory::isFull() const {
    return itemsAmount == limit;
}

void Inventory::clear() {
    inventoryItems.clear();
    itemsAmount = 0;
    for (int i = 0; i < limit; ++i){
        inventoryItems.push_back(ItemsInventoryID::Nothing);
    }
}

std::string Inventory::getStringInventory() const {
    std::string inv;
    std::string temp;
    for (int i = 0; i < limit; ++i){
        temp = std::to_string((int)inventoryItems.at(i));
        if (temp.size() == 1)
            inv += "0";
        inv += temp;
        if (i != limit-1)
            inv += "|";
    }
    return inv;
}

ItemsInventoryID Inventory::removeItem(ItemsInventoryID aItemToRemove) {
    auto iter = std::find(inventoryItems.begin(), inventoryItems.end(), aItemToRemove);
    if (iter == inventoryItems.end() || aItemToRemove == ItemsInventoryID::Nothing) {
        return ItemsInventoryID::Nothing;
    }
    (*iter) = ItemsInventoryID::Nothing;
    itemsAmount--;
    return aItemToRemove;
}

const std::vector<ItemsInventoryID> &Inventory::getInventoryItems() const {
    return inventoryItems;
}

bool Inventory::isEmpty() {
    return itemsAmount == 0;
}

Inventory::~Inventory() = default;
