#include "ObjectLayer.h"

ObjectLayer::ObjectLayer(rapidjson::Value &value) {
    name = value["name"].GetString();
    type = value["type"].GetString();
    rapidjson::Value::Array objectsArray = value["objects"].GetArray();
    for (auto &objectValue : objectsArray) {
        MapObject mapObject(objectValue);
        objects.push_back(mapObject);
    }
}

ObjectLayer::~ObjectLayer() = default;

const std::string &ObjectLayer::getName() const {
    return name;
}

void ObjectLayer::setName(const std::string &aName) {
    ObjectLayer::name = aName;
}

const std::vector<MapObject> &ObjectLayer::getObjects() const {
    return objects;
}

void ObjectLayer::setObjects(const std::vector<MapObject> &objectsVector) {
    ObjectLayer::objects = objectsVector;
}


