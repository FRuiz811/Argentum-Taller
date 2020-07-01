#include "StaticObject.h"

StaticObject::~StaticObject() = default;

StaticObject::StaticObject(rapidjson::Value &value) {
    float x = value["x"].GetFloat();
    float y = value["y"].GetFloat();
    float width = value["width"].GetFloat();
    float height = value["height"].GetFloat();
    position = Position(x, y, width, height);
    name = value["name"].GetString();
}

const Position &StaticObject::getPosition() const {
    return position;
}

const std::string &StaticObject::getName() const {
    return name;
}
