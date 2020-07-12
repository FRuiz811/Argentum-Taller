#ifndef ARGENTUM_TALLER_INVENTORY_H
#define ARGENTUM_TALLER_INVENTORY_H


#include "../common/Identificators.h"
#include <vector>

class Inventory {
private:
    std::vector<ItemsInventoryID> inventoryItems;
    uint8_t itemsAmount;
    uint8_t limit;
public:
    explicit Inventory(std::vector<ItemsInventoryID> inventoryItems);

    ItemsInventoryID getItem(int index) const;

    bool addItem(ItemsInventoryID aItemInventoryId);

    bool isFull() const;

    ItemsInventoryID removeItem(ItemsInventoryID aItemToRemove);

    std::string getStringInventory() const;

    void clear();

    virtual ~Inventory();
};


#endif //ARGENTUM_TALLER_INVENTORY_H
