#ifndef MERCHANT_H
#define MERCHANT_H

#include <unordered_map>
#include "../common/Identificators.h"
#include "../common/GameStats.h"
#include "Profession.h"

//Se optó por realizar esta clase como un Singleton debido a que 
//los diversos jugadores(Threads) no podrán modificar esta clase
//ya que los items que se venden/compran no se alteran dentro de 
//esta clase
class Merchant:public Profession {
private:
    Merchant();
    std::unordered_map<ItemsInventoryID, uint> items;
    static Merchant* merchant;
public:
    static Merchant* getInstance();

    void init(std::unordered_map<ItemsInventoryID, ItemInfo> itemsToInit);
    ItemsInventoryID buyItem(ItemsInventoryID idItem, uint* balance) const;

    uint sellItem(ItemsInventoryID idItem) const;

    const std::unordered_map<ItemsInventoryID,uint> getItems() const;

    ~Merchant();
};

#endif
