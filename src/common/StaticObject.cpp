#include "StaticObject.h"

StaticObject::~StaticObject() = default;

StaticObject::StaticObject(rapidjson::Value &value) {
    int x = value["x"].GetFloat();
    int y = value["y"].GetFloat();
    int width = value["width"].GetFloat();
    int height = value["height"].GetFloat();
    position = Position(x, y, width, height);
    id = value["id"].GetInt();
}

const Position &StaticObject::getPosition() const {
    return position;
}

//StaticObject::StaticObject(StaticObject &&other) noexcept {
//    std::swap(position, other.position);
//    std::swap(id, other.id);
//}
//
//StaticObject &StaticObject::operator=(StaticObject &&other) noexcept {
//    if (&other == this) {
//        return *this;
//    }
//    std::swap(position, other.position);
//    std::swap(id, other.id);
//    return *this;
//}

