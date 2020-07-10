#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H

#include <string>
#include "../common/Position.h"
#include "../common/Identificators.h"
#include "../common/GameObjectInfo.h"
#include "GameStatsConfig.h"
#include "Board.h"

class GameObject{
protected:
    Point point;
    std::shared_ptr<Cell> cell;
    uint id{};
    std::string textureHashId;
    Direction direction;
    NPCInfo infoInteracting;
public:
	explicit GameObject(uint id, Point initialPoint, std::shared_ptr<Cell> initialCell, Direction aDirection = Direction::down);

    GameObjectInfo getGameObjectInfo();

    uint getId() const;

    void setDirection(Direction direction);

    void setCell(std::shared_ptr<Cell> aCell);

    void setPoint(Point aPoint);

    std::shared_ptr<Cell> &getActualCell();

    void setTextureHashId(const std::string &textureHashId);

    virtual void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board& board, GameStatsConfig& gameStatsConfig) = 0;

    virtual CharacterStateID getStateId() = 0;

    virtual bool isDead() = 0;

    virtual uint receiveDamage(float damage, GameStatsConfig& gameStatsConfig) = 0;

    virtual NPCInfo interact(GameObject& character, InputInfo input) = 0;

    NPCInfo getInteractInfo() const;

    void setInteractInfo(NPCInfo info);

    virtual bool isReadyToRemove() = 0;

    virtual void remove(Board &board) = 0;

    ~GameObject();
};

#endif
