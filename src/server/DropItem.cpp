#include "DropItem.h"

DropItem::DropItem(ItemsInventoryID id, int amount) : id(id), amount(amount) {}

ItemsInventoryID DropItem::getId() const {
    return id;
}

int DropItem::getAmount() const {
    return amount;
}

DropItem::~DropItem() = default;
