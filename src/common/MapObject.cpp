#include "MapObject.h"

MapObject::~MapObject() = default;

MapObject::MapObject(rapidjson::Value &value) {
    int x = value["x"].GetFloat();
    int y = value["y"].GetFloat();
    int width = value["width"].GetFloat();
    int height = value["height"].GetFloat();
    position = Position(x, y, width, height);
    id = value["id"].GetInt();
}

const Position &MapObject::getPosition() const {
    return position;
}

//MapObject::MapObject(MapObject &&other) noexcept {
//    std::swap(position, other.position);
//    std::swap(id, other.id);
//}
//
//MapObject &MapObject::operator=(MapObject &&other) noexcept {
//    if (&other == this) {
//        return *this;
//    }
//    std::swap(position, other.position);
//    std::swap(id, other.id);
//    return *this;
//}

