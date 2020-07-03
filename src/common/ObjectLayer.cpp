#include "ObjectLayer.h"

ObjectLayer::ObjectLayer(rapidjson::Value &value) {
    name = value["name"].GetString();
    rapidjson::Value::Array objectsArray = value["objects"].GetArray();
    for (auto &objectValue : objectsArray) {
        StaticObject mapObject(objectValue);
        objects.push_back(std::move(mapObject));
    }
}

ObjectLayer::~ObjectLayer() = default;

const std::string &ObjectLayer::getName() const {
    return name;
}

std::vector<StaticObject> ObjectLayer::getObjects() {
    return objects;
}



