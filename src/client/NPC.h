#ifndef NPC_H
#define NPC_H

#include "Character.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Shield.h"
#include "Items/Weapon.h"
#include "TextureManager.h"
#include "../common/Identificators.h"
#include "characterStates/CharacterState.h"
#include "PlayerInfo.h"
#include <memory>

class NPC : public Character {
private:
    const TextureManager& manager;
    std::shared_ptr<Body>  body = nullptr;
	std::shared_ptr<Head> head = nullptr;
	std::shared_ptr<Helmet> helmet = nullptr;
	std::shared_ptr<Shield> shield = nullptr;
	std::shared_ptr<Weapon> weapon = nullptr;
    //Agregar Item en caso de que no sea un jugador;
    int frameHead{0};
    bool isAlive{true};
    bool isItem{false};

    void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);
	void setFrameHead();

public:
    NPC(const TextureManager& manager, const GameObjectInfo& gameObjectInfo);

    virtual void render(Camera& camera);
	virtual void update(double dt);

    void updatePlayerInfo(const GameObjectInfo& info);

    ~NPC();

};

#endif
