#include "Inventory.h"

#include <utility>
#include <algorithm>
#include "GameStatsConfig.h"

Inventory::Inventory(std::vector<ItemsInventoryID> aInventoryItems) :
inventoryItems(std::move(aInventoryItems)), itemsAmount(inventoryItems.size()),
limit(GameStatsConfig::getInventoryLimit()){
    for (int i = itemsAmount; i < limit; ++i){
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
}

std::string Inventory::getStringInventory() const {
    std::string inv;
    std::string temp;
    for (int i = 0; i < limit; ++i){
        temp = std::to_string((int)inventoryItems.at(i));
        if (temp.size() == 1)
            inv += "0";
        inv += temp;
        if (i != 8)
            inv += "|";
    }
    return std::move(inv);
}

ItemsInventoryID Inventory::removeItem(ItemsInventoryID aItemToRemove) {
    auto iter = std::find(inventoryItems.begin(), inventoryItems.end(), aItemToRemove);
    if (iter == inventoryItems.end()) {
        return ItemsInventoryID::Nothing;
    }
    (*iter) = ItemsInventoryID::Nothing;
    itemsAmount--;
    return aItemToRemove;
}

Inventory::~Inventory() = default;
