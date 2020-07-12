#ifndef PRIEST_H
#define PRIEST_H

#include "Profession.h"
#include <unordered_map>
#include <vector>
#include "../common/Identificators.h"
#include "states/State.h"

class Priest : public Profession {
private:
    Priest();
    std::unordered_map<ItemsInventoryID, uint,std::hash<ItemsInventoryID>> items;

    static Priest* priest;

    ItemsInventoryID buyItem(ItemsInventoryID idItem, uint* balance) const;

    std::unordered_map<ItemsInventoryID,uint> getItems() const;

public:
    static Priest* getInstance();

    void init(const std::map<ItemsInventoryID, ItemInfo>& itemsToInit);

    virtual NPCInfo getInfo(uint id);

    void processInput(GameCharacter &character, InputInfo inputInfo) override;

    ~Priest();
};

#endif
