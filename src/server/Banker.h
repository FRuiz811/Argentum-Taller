#ifndef BANKER_H
#define BANKER_H

#include <unordered_map>
#include <vector>
#include "../common/Identificators.h"
#include "Profession.h"

//Se optó por realizar esta clase como un Singleton debido a que 
//los diversos jugadores(Threads) tendrán solo acceso a sus items
//que estén depositados dentro del Banco, sin poder acceder a ningun
//otra "cuenta" que pertenezca al usuario.
class Banker: public Profession {
private:
    Banker();
    std::unordered_map<uint, std::vector<ItemsInventoryID>> accountsItems;
    std::unordered_map<uint, uint> accountsGold;
    static Banker* banker;
    
    void createNewAccount(uint accountHolder);

    std::vector<ItemsInventoryID> getMyItems(uint accountHolder);

    uint checkBalance(uint accountHolder);

    ItemsInventoryID retireItem(uint accountHolder, uint item);

    void depositItem(uint accountHolder, ItemsInventoryID idItem);

    void depositGold(uint accountHolder, uint amountGold);

    uint retireGold(uint accountHolder, uint amountGold);
    
public:
    static Banker* getInstance();

    virtual NPCInfo getInfo(uint id);

    ~Banker();
};

#endif