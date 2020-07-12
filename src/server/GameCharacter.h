#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "../common/PlayerInfo.h"
#include "../common/StaticObject.h"
#include "states/State.h"
#include "../common/InputQueue.h"
#include "../common/Identificators.h"
#include "Inventory.h"
#include <vector>
#include <memory>

class GameCharacter : public GameObject{
private:
    RaceID race{RaceID::Nothing};
    GameClassID gameClass{GameClassID::Nothing};
    uint goldAmount;
    uint life;
    uint mana;
    float exp;
    std::unique_ptr<State> state;
    Inventory inventory;
    InputQueue queueInputs;
    WeaponID weapon{WeaponID::Nothing};
    ShieldID shield{ShieldID::Nothing};
    HelmetID helmet{HelmetID::Nothing};
    BodyID body{BodyID::Nothing};

    std::string updateTextureHashId();
    void consumePotion(const ItemInfo& potion);

public:
	GameCharacter(uint id, RaceID aRace, GameClassID aClass, std::shared_ptr<Cell> initialCell, Point initialPoint);

	PlayerInfo getPlayerInfo();

	bool hasAnInputInfo();

	InputInfo getNextInputInfo();

	bool inventoryIsFull();

	bool addItemToInventory(ItemsInventoryID aItemInventoryId);

	ItemsInventoryID removeItemFromInventory(ItemsInventoryID aItemToFind);

	void gainGold(int aGoldAmount);

    bool isReadyToRemove() override;

    WeaponID getWeapon();

    void gainExp(float newExp);

    float getMaxLife() override;

    void cure();

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    void receiveDamage(float damage, WeaponID weaponId) override;

    bool isDead();

    ~GameCharacter();

    RaceID getRace() const;

    void remove(Board &board) override;

    GameClassID getGameClass() const;

    uint getGoldAmount();

    void setGoldAmount(uint goldAmount);

    CharacterStateID getStateId() override;

    uint getLife() const;

    uint getMana() const;

    float getExp() const;

    uint getLevel() const;

    std::string getStringInventory() const;

    InputQueue &getQueueInputs();

    virtual NPCInfo interact(GameObject& character, InputInfo input);

    void equipItem(int itemToEquip);
};

#endif
