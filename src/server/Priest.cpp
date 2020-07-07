#include "Priest.h"

Priest* Priest::priest = 0;

Priest::Priest() :items() {
    this->actions.push_back(ActionsProfessionID::Buy);
    this->actions.push_back(ActionsProfessionID::Cure);
    this->actions.push_back(ActionsProfessionID::Resurrect);
}


Priest* Priest::getInstance() {
    if (priest == 0)
        priest = new Priest();
    return priest;
}

void Priest::init(std::unordered_map<ItemsInventoryID, ItemInfo>itemsToInit) {
    for (auto iter: itemsToInit){
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

const std::unordered_map<ItemsInventoryID,uint> Priest::getItems() const {
    return std::move(items);
}

NPCInfo Priest::getInfo(uint id) {
    NPCInfo info;
    info.type = 2;
    info.actions = actions;
    info.gold = 0;
    info.items = getItems();
    return info;
}

void Priest::cure(uint* health, uint maxHelth, uint* mana, uint maxMana) const {
    *health = maxHelth;
    *mana = maxMana;
}

void Priest::resurrect(uint* health, uint maxHelth, uint* mana, uint maxMana,State* state) const {
    if (state->getStateId() == CharacterStateID::Dead){
        cure(health,maxHelth, mana,maxMana);
        InputInfo info;
        info.input = InputID::resurrect;
        state->setNextState(info);
    }
}

Priest::~Priest() {}
