#include "StaticObject.h"

StaticObject::~StaticObject() = default;

StaticObject::StaticObject(rapidjson::Value &value) {
    int x = value["x"].GetFloat();
    int y = value["y"].GetFloat();
    int width = value["width"].GetFloat();
    int height = value["height"].GetFloat();
    topLeft = Point(x, y);
    topRight = Point(x + width, y);
    bottomLeft = Point(x, y + height);
    bottomRight = Point(x + width, y + height);
    name = value["name"].GetString();
}

const std::string &StaticObject::getName() const {
    return name;
}

const Point &StaticObject::getTopLeft() const {
    return topLeft;
}

const Point &StaticObject::getTopRight() const {
    return topRight;
}

const Point &StaticObject::getBottomLeft() const {
    return bottomLeft;
}

const Point &StaticObject::getBottomRight() const {
    return bottomRight;
}
