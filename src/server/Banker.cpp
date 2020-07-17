#include "Banker.h"

Banker* Banker::banker = nullptr;

Banker::Banker() :accountsItems(), accountsGold(2500) {
    this->actions.push_back(ActionsProfessionID::DepositGold);
    this->actions.push_back(ActionsProfessionID::DepositItem);
    this->actions.push_back(ActionsProfessionID::RetireItem);
    this->actions.push_back(ActionsProfessionID::RetireGold);
}

Banker* Banker::getInstance() {
    if (banker == nullptr)
        banker = new Banker();
    return banker;
}

std::vector<ItemsInventoryID> Banker::getMyItems(uint accountHolder) {
    auto iter = accountsItems.find(accountHolder);
    if (iter == accountsItems.end()) {
        createNewAccount(accountHolder);
        iter = accountsItems.find(accountHolder);
    }
    return (*iter).second;
}

uint Banker::checkBalance(uint accountHolder) {
    auto iter = accountsGold.find(accountHolder);
    if (iter == accountsGold.end()) {
        createNewAccount(accountHolder);
        return 0;
    }
    return accountsGold[accountHolder];
}

void Banker::createNewAccount(uint accountHolder) {
    uint gold = 0;
    accountsGold.insert({accountHolder,gold});
    std::vector<ItemsInventoryID> emptyAccount;
    emptyAccount.push_back(ItemsInventoryID::HealthPotion);
    accountsItems.insert({accountHolder,emptyAccount});
}

ItemsInventoryID Banker::retireItem(uint accountHolder, uint item) {
    auto iter = accountsItems.find(accountHolder);  
    if (iter == accountsItems.end()) {
        createNewAccount(accountHolder);
        return ItemsInventoryID::Nothing;
    }
    if (accountsItems[accountHolder].size() == 0)
        return ItemsInventoryID::Nothing;
    ItemsInventoryID itemToRetire = (*iter).second.at(item);
    (*iter).second.at(item) = ItemsInventoryID::Nothing;
    auto it = (*iter).second.begin();
    while (it != (*iter).second.end()) {
        if (*it == ItemsInventoryID::Nothing) {
            it = (*iter).second.erase(it);
        } else {
            it++;
        }
    }
    return itemToRetire;
}

NPCInfo Banker::getInfo(uint id) {
    NPCInfo info;
    info.type = 3;
    info.actions = actions;
    info.gold = checkBalance(id);
    info.itemsInBank = getMyItems(id);
    return info;
}


void Banker::depositItem(uint accountHolder, ItemsInventoryID idItem) {
    auto iter = accountsItems.find(accountHolder);
    if (iter == accountsItems.end()) {
        createNewAccount(accountHolder);
        iter = accountsItems.find(accountHolder);
    }
    (*iter).second.push_back(idItem);
}

void Banker::depositGold(uint accountHolder, uint amountGold) {
    auto iter = accountsGold.find(accountHolder);
    if (iter == accountsGold.end())
        createNewAccount(accountHolder);
    accountsGold[accountHolder] += amountGold;
}

uint Banker::retireGold(uint accountHolder, uint amountGold) {
    auto iter = accountsGold.find(accountHolder);
    if (iter == accountsGold.end()) {
        createNewAccount(accountHolder);
        return 0;
    }
    if (accountsGold[accountHolder] < amountGold) {
        amountGold = accountsGold[accountHolder];
        accountsGold[accountHolder] = 0;
    } else {
        accountsGold[accountHolder] -= amountGold;
    }
    return amountGold;
}

void Banker::processInput(GameCharacter &character, InputInfo inputInfo) {
    bool addedToInventory;
    ItemsInventoryID aItem;
    int gold;
    switch (inputInfo.input) {
        case InputID::depositItem:
            character.removeItemFromInventory(ItemsInventoryID(inputInfo.aditional));
            depositItem(character.getId(),ItemsInventoryID(inputInfo.aditional));
            break;
        case InputID::retireItem:
            aItem = retireItem(character.getId(), inputInfo.aditional);
            if (aItem != ItemsInventoryID::Nothing) {
                addedToInventory = character.addItemToInventory(aItem);
                if(!addedToInventory)
                    depositItem(character.getId(), aItem);
            }
            break;
        case InputID::depositGold:
            gold = character.getGoldAmount();
            if (inputInfo.aditional > gold)
                inputInfo.aditional = gold;
            depositGold(character.getId(), inputInfo.aditional);
            character.setGoldAmount(character.getGoldAmount() - inputInfo.aditional);
            break;
        case InputID::retireGold:
            gold = retireGold(character.getId(), inputInfo.aditional);
            character.gainGold(gold);
            break;
        default:
            break;
    }

}
