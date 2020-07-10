#include "Banker.h"

Banker* Banker::banker = 0;

Banker::Banker() :accountsItems(), accountsGold(2500) {
    this->actions.push_back(ActionsProfessionID::DepositGold);
    this->actions.push_back(ActionsProfessionID::DepositItem);
    this->actions.push_back(ActionsProfessionID::RetireItem);
    this->actions.push_back(ActionsProfessionID::RetireGold);
}

Banker* Banker::getInstance() {
    if (banker == 0)
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
    return (*iter).second;
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
    (*iter).second += amountGold;
}

uint Banker::retireGold(uint accountHolder, uint amountGold) {
    auto iter = accountsGold.find(accountHolder);
    if (iter == accountsGold.end()) {
        createNewAccount(accountHolder);
        return 0;
    }
    if ((*iter).second < amountGold) {
        (*iter).second = 0;
    } else {
        (*iter).second -= amountGold;
    }
    return amountGold;
}
