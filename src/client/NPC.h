#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Items/Item.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "Items/Animation.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "../common/Identificators.h"
#include "../common/GameObjectInfo.h"
#include "characterStates/CharacterState.h"
#include <memory>

class NPC : public Character {
private:
    const TextureManager& manager;
    const MusicManager& mixer;
    std::shared_ptr<Body>  body = nullptr;
	std::shared_ptr<Head> head = nullptr;
	std::shared_ptr<Helmet> helmet = nullptr;
	std::shared_ptr<Shield> shield = nullptr;
	std::shared_ptr<Weapon> weapon = nullptr;
	std::shared_ptr<Animation> animation = nullptr;
    int frameHead{0};
    std::shared_ptr<CharacterState> state = nullptr;

    bool aItem{false};
    std::shared_ptr<Item> item = nullptr;
    void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);
	void setFrameHead();
    void setState(CharacterStateID newState);
    void setAnimation(WeaponID weaponEnemy);
    void setItem(ItemsInventoryID itemId);
    MusicID selectSound();

public:
    NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo, const MusicManager& mixer);

    virtual void render(Camera& camera);
	virtual void update(double dt);
    bool isItem() const;
    void updatePlayerInfo(const GameObjectInfo& info);
    CharacterStateID& getState();
    ~NPC();

};

#endif
