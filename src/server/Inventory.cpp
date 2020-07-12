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

void Inventory::addItem(ItemsInventoryID aItemInventoryId) {
    if (!isFull() && aItemInventoryId != ItemsInventoryID::Nothing) {
        auto iter = std::find(inventoryItems.begin(), inventoryItems.end(), ItemsInventoryID::Nothing);
        (*iter) = aItemInventoryId;
        itemsAmount++;
    }
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
    return (*iter);
}

const std::vector<ItemsInventoryID> &Inventory::getInventoryItems() const {
    return inventoryItems;
}

bool Inventory::isEmpty() {
    return itemsAmount == 0;
}

Inventory::~Inventory() = default;
