#include "GameObjectsContainer.h"

GameObjectsContainer::GameObjectsContainer() = default;

GameObjectsContainer::~GameObjectsContainer() = default;

void GameObjectsContainer::addGameObject(const std::shared_ptr<GameObject>& aGameObject, uint id) {
    gameObjects.insert(std::pair<uint, std::shared_ptr<GameObject>>(id, aGameObject));
}

std::vector<GameObjectInfo> GameObjectsContainer::getUpdatedGameObjectsInfo() {
    std::vector<GameObjectInfo> gameObjectsInfo;
    for (auto& gameObjectPair : gameObjects) {
        gameObjectsInfo.push_back(gameObjectPair.second->getGameObjectInfo());
    }
    return gameObjectsInfo;
}

void GameObjectsContainer::update(Board& board, GameStatsConfig& gameStatsConfig) {
    for (auto& gameObjectPair : gameObjects) {
        gameObjectPair.second->update(gameObjects, board, gameStatsConfig);
    }
}

std::shared_ptr<GameObject> GameObjectsContainer::getGameObject(uint id) {
    return gameObjects.at(id);
}

void GameObjectsContainer::deleteGameObject(uint id) {
    this->gameObjects.erase(id);
}
