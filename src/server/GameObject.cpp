#include "GameObject.h"

#include <utility>

GameObjectInfo GameObject::getGameObjectInfo() {
    return GameObjectInfo(id, point, textureHashId, direction,getStateId(),false);
}

uint GameObject::getId() const {
    return id;
}

void GameObject::setDirection(Direction direction) {
    GameObject::direction = direction;
}

void GameObject::setTextureHashId(const std::string &textureHashId) {
    GameObject::textureHashId = textureHashId;
}

GameObject::GameObject(uint id, Point initialPoint, std::shared_ptr<Cell> initialCell, Direction aDirection) :
    id(id), point(initialPoint), cell(initialCell), direction(aDirection) {}

std::shared_ptr<Cell> &GameObject::getActualCell() {
    return cell;
}

void GameObject::setCell(std::shared_ptr<Cell> aCell) {
    cell = std::move(aCell);
}

void GameObject::setPoint(Point aPoint) {
    point = aPoint;
}

GameObject::~GameObject()= default;