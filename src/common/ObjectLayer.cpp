#include "ObjectLayer.h"

ObjectLayer::ObjectLayer(rapidjson::Value &value) {
    name = value["name"].GetString();
    type = value["type"].GetString();
    rapidjson::Value::Array objectsArray = value["objects"].GetArray();
    for (auto &objectValue : objectsArray) {
        MapObject mapObject(objectValue);
        objects.push_back(std::move(mapObject));
    }
}

ObjectLayer::~ObjectLayer() = default;

const std::string &ObjectLayer::getName() const {
    return name;
}

std::vector<MapObject>&& ObjectLayer::getObjects() {
    return std::move(objects);
}

//ObjectLayer::ObjectLayer(ObjectLayer &&other) noexcept {
//    std::swap(objects, other.objects);
//    std::swap(name, other.name);
//}
//
//ObjectLayer &ObjectLayer::operator=(ObjectLayer &&other) noexcept {
//   if (&other == this) {
//       return *this;
//   }
//    std::swap(objects, other.objects);
//    std::swap(name, other.name);
//    return *this;
//}



