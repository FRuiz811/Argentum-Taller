#ifndef MERCHANT_H
#define MERCHANT_H

#include <unordered_map>
#include "../common/Identificators.h"
#include "GameStats.h"
#include "Profession.h"
#include "GameCharacter.h"

//Se optó por realizar esta clase como un Singleton debido a que 
//los diversos jugadores(Threads) no podrán modificar esta clase
//ya que los items que se venden/compran no se alteran dentro de 
//esta clase
class Merchant:public Profession {
private:
    Merchant();
    std::unordered_map<ItemsInventoryID, uint, std::hash<ItemsInventoryID>> items;

    static Merchant* merchant;

    ItemsInventoryID buyItem(ItemsInventoryID idItem, uint* balance) const;

    uint sellItem(ItemsInventoryID idItem) const;

    std::unordered_map<ItemsInventoryID,uint> getItems() const;
public:
    static Merchant* getInstance();

    void init(const std::map<ItemsInventoryID, ItemInfo>& itemsToInit);

    NPCInfo getInfo(uint id) override;

    void processInput(GameCharacter &character, InputInfo inputInfo) override;

    virtual ~Merchant();
};

#endif
