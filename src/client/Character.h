#ifndef CHARACTER_H
#define CHARACTER_H

#include "Camera.h"
#include "../common/Identificators.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "Items/Animation.h"
#include "Items/Head.h"
#include "Items/Body.h"
#include "Items/Helmet.h"
#include "Items/Weapon.h"
#include "Items/Shield.h"
#include <memory>

class Character {
protected:
    int id;
	float posX, posY;
    Direction direction{Direction::down};
    const TextureManager& manager;
    const MusicManager& mixer;
    std::shared_ptr<Body>  body = nullptr;
	std::shared_ptr<Head> head = nullptr;
	std::shared_ptr<Helmet> helmet = nullptr;
	std::shared_ptr<Shield> shield = nullptr;
	std::shared_ptr<Weapon> weapon = nullptr;
	std::shared_ptr<Animation> animation = nullptr;
    int frameHead{0};

    void setArmor(BodyID newArmor);
	void setShield(ShieldID newShield);
	void setHelmet(HelmetID newHelmet);
	void setHead(HeadID head);
	void setWeapon(WeaponID newWeapon);
	void setFrameHead();
    void setAnimation(WeaponID weaponEnemy);

public:
    Character(float posX, float posY, int id,const TextureManager& manager,
    const MusicManager& mixer);

    virtual void render(Camera& camera);

    virtual void update(double dt) = 0;

    Direction getDirection() const;
    
    Point getPosition() const;

    int getId() const;
    
    ~Character();

};

#endif
