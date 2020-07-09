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
    BoardPosition boardPosition;
    uint id{};
    std::string textureHashId;
    Direction direction;
    NPCInfo infoInteracting;
public:
	explicit GameObject(uint id, Direction direction = Direction::down);

	GameObject(GameObject&&) noexcept;
	GameObject& operator=(GameObject&& other)  noexcept;

    GameObjectInfo getGameObjectInfo();

    uint getId() const;

    BoardPosition& getBoardPosition();

    void setDirection(Direction direction);

    void setTextureHashId(const std::string &textureHashId);

    virtual void update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board& board, GameStatsConfig& gameStatsConfig) = 0;

    virtual CharacterStateID getStateId() = 0;

    virtual uint receiveDamage(float damage, GameStatsConfig& gameStatsConfig) = 0;

    virtual NPCInfo interact(GameObject& character, InputInfo input) = 0;

    NPCInfo getInteractInfo() const;

    void setInteractInfo(NPCInfo info);
    
    ~GameObject();
};

#endif
