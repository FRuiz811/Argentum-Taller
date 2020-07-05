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
    Position position;
    uint id{};
    std::string textureHashId;
    Direction direction;
    CharacterStateID state;
public:
	GameObject();
	explicit GameObject(uint id, Direction direction = Direction::down,
        CharacterStateID state = CharacterStateID::Still);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    GameObjectInfo getGameObjectInfo();

    uint getId() const;

    void setPosition(const Position &position);

    Position &getPosition();

    void setDirection(Direction direction);

    void setTextureHashId(const std::string &textureHashId);

    virtual void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board& board, GameStatsConfig& gameStatsConfig) = 0;

    ~GameObject();
};

#endif
