#include "GameObjectInfo.h"

#include <utility>

GameObjectInfo::~GameObjectInfo() = default;


GameObjectInfo::GameObjectInfo(uint id, const Point &point, std::string textureHashId) :
id(id), point(point), textureHashId(std::move(textureHashId)) {}

uint GameObjectInfo::getId() const {
    return id;
}

const Point &GameObjectInfo::getPoint() const {
    return point;
}

const std::string &GameObjectInfo::getTextureHashId() const {
    return textureHashId;
}

uint GameObjectInfo::getX() const {
    return point.x;
}

uint GameObjectInfo::getY() const {
    return point.y;
}

GameObjectInfo::GameObjectInfo() = default;
