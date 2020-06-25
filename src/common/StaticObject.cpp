#include "StaticObject.h"

StaticObject::~StaticObject() = default;

StaticObject::StaticObject(rapidjson::Value &value) {
    int x = value["x"].GetFloat();
    int y = value["y"].GetFloat();
    int width = value["width"].GetFloat();
    int height = value["height"].GetFloat();
    position = Position(x, y, width, height);
    name = value["name"].GetString();
}

const Position &StaticObject::getPosition() const {
    return position;
}

const std::string &StaticObject::getName() const {
    return name;
}
