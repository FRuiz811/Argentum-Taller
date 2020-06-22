#include "MapObject.h"

MapObject::~MapObject() = default;

MapObject::MapObject(rapidjson::Value &value) {
    int x = value["x"].GetInt();
    int y = value["y"].GetInt();
    int width = value["width"].GetInt();
    int height = value["height"].GetInt();
    position = Position(x, y, width, height);
    id = value["id"].GetInt();
}

MapObject::MapObject(MapObject &&other) {
    std::swap(position, other.position);
    std::swap(id, other.id);
}

const Position &MapObject::getPosition() const {
    return position;
}

