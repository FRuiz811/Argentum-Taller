#include "ServerItem.h"

ServerItem::~ServerItem() = default;

ServerItem::ServerItem(ItemsInventoryID id, int16_t amount) : id(id), amount(amount) {}

ItemsInventoryID ServerItem::getId() const {
    return id;
}

void ServerItem::increaseAmount() {
    amount++;
}

void ServerItem::decreseAmount() {
    amount--;
    if (amount == 0) {
        id = ItemsInventoryID::Nothing;
        amount++;
    }
}

bool operator==(ServerItem &thisItem, const ServerItem &otherItem) {
    return thisItem.getId() == otherItem.getId();
}

bool operator!=(ServerItem &thisItem, const ServerItem &otherItem) {
    return !(thisItem == otherItem);
}
