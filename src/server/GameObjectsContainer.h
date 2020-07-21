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

    void addGameObject(std::shared_ptr<GameObject> aGameObject, uint id);
    
    std::vector<std::shared_ptr<GameObject>> getUpdatedGameObjects();

    void update(Board& board);

    virtual ~GameObjectsContainer();

    void deleteGameObject(uint id, Board &board);

    void removeCreaturesAndItems(Board& board);
};
#endif //ARGENTUM_TALLER_GAMEOBJECTSCONTAINER_H
