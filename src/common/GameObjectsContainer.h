#ifndef ARGENTUM_TALLER_GAMEOBJECTSCONTAINER_H
#define ARGENTUM_TALLER_GAMEOBJECTSCONTAINER_H


#include <memory>
#include <unordered_map>
#include "GameObject.h"

class GameObjectsContainer {
private:
    std::unordered_map<uint, std::shared_ptr<GameObject>, std::hash<uint>> gameObjects;
public:
    GameObjectsContainer();

    void addGameObject(const std::shared_ptr<GameObject>& aGameObject, uint id);

    std::vector<GameObjectInfo> getUpdatedGameObjectsInfo();

    void update(Board& board, GameStatsConfig& gameStatsConfig);

    std::shared_ptr<GameObject> getGameObject(uint id);

    virtual ~GameObjectsContainer();

    void deleteGameObject(const uint i);
};
#endif //ARGENTUM_TALLER_GAMEOBJECTSCONTAINER_H
