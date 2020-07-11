#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "../common/PlayerInfo.h"
#include "../common/StaticObject.h"
#include "states/State.h"
#include "../common/InputQueue.h"
#include "../common/Identificators.h"
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
    std::vector<ItemsInventoryID> inventory;
    InputQueue queueInputs;
    WeaponID weapon{WeaponID::Nothing};
    ShieldID shield{ShieldID::Nothing};
    HelmetID helmet{HelmetID::Nothing};
    BodyID body{BodyID::Nothing};

    std::string updateTextureHashId();
    void consumePotion(ItemInfo potion);

public:
	GameCharacter(uint id, RaceID aRace, GameClassID aClass, std::shared_ptr<Cell> initialCell, Point initialPoint);

	PlayerInfo getPlayerInfo();

	bool hasAnInputInfo();

	InputInfo getNextInputInfo();

    bool isReadyToRemove() override;

    WeaponID getWeapon();

    void gainExp(float newExp);

    float getMaxLife() override;

    void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) override;

    uint receiveDamage(float damage) override;

    bool isDead();

    ~GameCharacter();

    RaceID getRace() const;

    void remove(Board &board) override;

    GameClassID getGameClass() const;

    uint getGoldAmount() const;

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
