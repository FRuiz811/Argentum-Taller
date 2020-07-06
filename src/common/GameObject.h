#ifndef OBJETOJUEGO_H
#define OBJETOJUEGO_H

#include <string>
#include "Position.h"
#include "Identificators.h"
#include "GameObjectInfo.h"
#include "GameStatsConfig.h"
#include "Board.h"

class GameObject{
protected:
    BoardPosition boardPosition;
    uint id{};
    std::string textureHashId;
    Direction direction;
public:
	explicit GameObject(uint id, Direction direction = Direction::down);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    GameObjectInfo getGameObjectInfo();

    virtual CharacterStateID getStateId() = 0;

    uint getId() const;

    BoardPosition& getBoardPosition();

    void setDirection(Direction direction);

    void setTextureHashId(const std::string &textureHashId);

    virtual void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board& board, GameStatsConfig& gameStatsConfig) = 0;

    ~GameObject();
};

#endif
