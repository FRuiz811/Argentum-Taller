#ifndef ARGENTUM_TALLER_DROPITEM_H
#define ARGENTUM_TALLER_DROPITEM_H

#include "../common/Identificators.h"

class DropItem {
private:
    ItemsInventoryID id;
    int amount{};

public:
    DropItem(ItemsInventoryID id, int amount);

    ItemsInventoryID getId() const;

    int getAmount() const;

    virtual ~DropItem();
};


#endif //ARGENTUM_TALLER_DROPITEM_H
