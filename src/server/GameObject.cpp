#include "GameObject.h"

GameObject::GameObject(GameObject&& other)  noexcept {
    std::swap(boardPosition, other.boardPosition);
}

GameObject &GameObject::operator=(GameObject &&other) noexcept{
    if (&other == this) {
        return *this;
    }
    std::swap(boardPosition, other.boardPosition);
    return *this;
}

GameObject::GameObject(uint id, Direction direction):
    id(id), direction(direction) {}

GameObjectInfo GameObject::getGameObjectInfo() {
    return GameObjectInfo(id, boardPosition.getPosition().getPoint(), textureHashId, direction,getStateId(),false);
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

BoardPosition& GameObject::getBoardPosition() {
    return boardPosition;
}

NPCInfo GameObject::getInteractInfo() const {
    return this->infoInteracting;
}

void GameObject::setInteractInfo(NPCInfo info) {
    this->infoInteracting = info;
}

GameObject::~GameObject()= default;