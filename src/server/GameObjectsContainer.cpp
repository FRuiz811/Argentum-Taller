#include <iostream>
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

std::vector<std::shared_ptr<GameObject>> GameObjectsContainer::getUpdatedGameObjects() {
    std::vector<std::shared_ptr<GameObject>> objects;
    for (auto& gameObjectPair : gameObjects) {
        objects.push_back(gameObjectPair.second);
    }
    return objects;
}


void GameObjectsContainer::update(Board& board) {
    for (auto& gameObjectPair : gameObjects) {
        gameObjectPair.second->update(gameObjects, board);
    }
}

std::shared_ptr<GameObject> GameObjectsContainer::getGameObject(uint id) {
    return gameObjects.at(id);
}

void GameObjectsContainer::deleteGameObject(uint id, Board &board) {
    this->gameObjects.at(id)->remove(board);
    this->gameObjects.erase(id);
}

void GameObjectsContainer::removeDeadCreatures(Board &board) {
    auto iter = this->gameObjects.begin();
    while (iter != this->gameObjects.end()) {
        if ((*iter).second->isReadyToRemove()) {
            (*iter).second->remove(board);
            iter = this->gameObjects.erase(iter);
        } else {
            iter++;
        }
    }
}
