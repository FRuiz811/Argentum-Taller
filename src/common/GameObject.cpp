#include "GameObject.h"

GameObject::GameObject(GameObject&& other)  noexcept {
    std::swap(position, other.position);
}

Position &GameObject::getPosition() {
    return position;
}

GameObject &GameObject::operator=(GameObject &&other) noexcept{
    if (&other == this) {
        return *this;
    }
    std::swap(position, other.position);
    return *this;
}

void GameObject::setPosition(const Position &position) {
    GameObject::position = position;
}

GameObject::GameObject(uint id): id(id) {}

GameObjectInfo GameObject::getGameObjectInfo() {
    return GameObjectInfo(id, position.getPoint(), textureHashId, direction,CharacterStateID::Still,false);
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

GameObject::GameObject() = default;

GameObject::~GameObject()= default;