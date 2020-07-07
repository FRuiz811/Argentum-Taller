#ifndef PRIEST_H
#define PRIEST_H

#include "Profession.h"
#include <unordered_map>
#include <vector>
#include "../common/Identificators.h"
#include "../common/State.h"

class Priest : public Profession {
private:
    Priest();
    std::unordered_map<ItemsInventoryID, uint> items;

    static Priest* priest;

public:
    static Priest* getInstance();

    void init(std::unordered_map<ItemsInventoryID, ItemInfo> itemsToInit);

    ItemsInventoryID buyItem(ItemsInventoryID idItem, uint* balance) const;

    void cure(uint* health, uint maxHelth, uint* mana, uint maxMana) const;

    void resurrect(uint* health, uint maxHelth, uint* mana, uint maxMana,State* state) const;

    const std::unordered_map<ItemsInventoryID,uint> getItems() const;

    ~Priest();
};

#endif
