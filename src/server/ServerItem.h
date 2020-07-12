#ifndef ARGENTUM_TALLER_SERVERITEM_H
#define ARGENTUM_TALLER_SERVERITEM_H


#include "../common/Identificators.h"

class ServerItem {
private:
    ItemsInventoryID id;
    int16_t amount;
public:
    ServerItem(ItemsInventoryID id, int16_t amount);

    ItemsInventoryID getId() const;

    friend bool operator==(ServerItem &thisItem, const ServerItem& otherItem);

    friend bool operator!=(ServerItem &thisItem, const ServerItem& otherItem);

    void increaseAmount();

    void decreseAmount();

    virtual ~ServerItem();

};


#endif //ARGENTUM_TALLER_SERVERITEM_H
