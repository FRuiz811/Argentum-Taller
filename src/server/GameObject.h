#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H

#include <string>
#include "../common/Identificators.h"
#include "../common/GameObjectInfo.h"
#include "GameStatsConfig.h"
#include "Board.h"
#include "DropItem.h"

class GameObject{
protected:
    Point point;
    std::shared_ptr<Cell> cell;
    uint id{};
    std::string textureHashId;
    Direction direction;
    NPCInfo infoInteracting;
    uint level;
    WeaponID interactWeapon;
public:
	explicit GameObject(uint id, Point initialPoint, std::shared_ptr<Cell> initialCell, Direction aDirection = Direction::down);

    GameObjectInfo getGameObjectInfo();

    virtual PlayerInfo getPlayerInfo();

    uint getId() const;

    void setDirection(Direction direction);

    void setCell(std::shared_ptr<Cell> aCell);

    void setPoint(Point aPoint);

    virtual bool isItem() = 0;

    virtual bool canDropsItems() = 0;

    virtual std::vector<DropItem> getDrop() = 0;

    void setInteractWeapon(WeaponID interactWeapon);

    std::shared_ptr<Cell> &getActualCell();

    void setTextureHashId(const std::string &textureHashId);

    virtual float getMaxLife() = 0;

    uint getLevel();

    virtual void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board& board) = 0;

    virtual CharacterStateID getStateId() = 0;

    virtual bool isDead() = 0;

    virtual void receiveDamage(float damage, WeaponID weaponId) = 0;

	virtual NPCInfo interact(GameObject& character, InputInfo input) = 0;

    NPCInfo getInteractInfo() const;

    void setInteractInfo(NPCInfo info);

    virtual bool isReadyToRemove() = 0;

    virtual void remove(Board &board) = 0;

    virtual bool canBeAttacked(int enemyLevel) const = 0;

    ~GameObject();
};

#endif
