#ifndef ARGENTUM_TALLER_OBJECTITEM_H
#define ARGENTUM_TALLER_OBJECTITEM_H


#include "GameObject.h"

class ObjectItem : public GameObject {
private:
    int timeToBeRemove = 45 * 300;
    int amount;
    ItemsInventoryID itemId;
public:
    ObjectItem(uint id, const Point &initialPoint, const std::shared_ptr<Cell> &initialCell, const DropItem& dropItem);

    float getMaxLife() override;

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    CharacterStateID getStateId() override;

    bool isDead() override;

    PlayerInfo getPlayerInfo() override;

    bool hasAnInputInfo() override;

    InputInfo getNextInputInfo() override;

    bool isItem() override;

    void take();

    int getAmount() const;

    ItemsInventoryID getItemId() const;

    bool canDropsItems() override;

    std::vector<DropItem> getDrop() override;

    void receiveDamage(float damage, WeaponID weaponId) override;

    NPCInfo interact(GameObject &character, InputInfo input) override;

    bool isReadyToRemove() override;

    void remove(Board &board) override;

    virtual ~ObjectItem();

    bool canBeAttacked(int enemyLevel) const;
};


#endif //ARGENTUM_TALLER_OBJECTITEM_H
