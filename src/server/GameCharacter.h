#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "../common/PlayerInfo.h"
#include "../common/StaticObject.h"
#include "../common/InputQueue.h"
#include "../common/Identificators.h"
#include "Inventory.h"
#include "GameObject.h"
#include <vector>
#include <memory>
#include <states/StatePoolCharacter.h>

class GameCharacter : public GameObject{
private:
    RaceID race{RaceID::Nothing};
    GameClassID gameClass{GameClassID::Nothing};
    uint goldAmount;
    float life;
    float mana;
    float exp;
    StatePoolCharacter statePool;
    InputQueue queueInputs;
    Inventory inventory;
    WeaponID weapon{WeaponID::Nothing};
    ShieldID shield{ShieldID::Nothing};
    HelmetID helmet{HelmetID::Nothing};
    BodyID body{BodyID::Nothing};
    ItemsInventoryID itemToDrop = ItemsInventoryID::Nothing;

    std::string updateTextureHashId();
    void consumePotion(const ItemInfo& potion);

public:
	GameCharacter(uint id, RaceID aRace, GameClassID aClass, std::shared_ptr<Cell> initialCell, Point initialPoint);

	bool hasAnInputInfo();

    PlayerInfo getPlayerInfo() override;

	void consumeMana();

    void upLevel();

    bool canPerformAttack();

	InputInfo getNextInputInfo();

	bool inventoryIsFull();

	bool addItemToInventory(ItemsInventoryID aItemInventoryId);

	ItemsInventoryID removeItemFromInventory(ItemsInventoryID aItemToFind);

	void gainGold(int aGoldAmount);

    bool isReadyToRemove() override;

    WeaponID getWeapon();

    std::vector<DropItem> getDrop() override;

    void gainExp(float newExp);

    bool isItem() override;

    bool canDropsItems() override;

    float getMaxLife() override;

    void cure();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void receiveDamage(float damage, WeaponID weaponId) override;

    bool isDead() override;

    ~GameCharacter();

    RaceID getRace() const;

    void remove(Board &board) override;

    uint getGoldAmount();

    void setGoldAmount(uint goldAmount);

    CharacterStateID getStateId() override;

    float getExp() const;

    std::string getStringInventory() const;

    InputQueue &getQueueInputs();

    NPCInfo interact(GameObject& character, InputInfo input) override;

    void equipItem(int itemToEquip);

    void unequipItem(int itemToUnequip);

    bool takeItem(ItemsInventoryID anItemId, int amount);

    void dropItem(int index);

    void updateHealthAndMana();

    bool canBeAttacked(int enemyLevel) const;
};

#endif
