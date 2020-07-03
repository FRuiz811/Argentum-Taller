#include "TileLayer.h"

#include <utility>

TileLayer::TileLayer() = default;

TileLayer::~TileLayer() = default;

TileLayer::TileLayer(rapidjson::Value & value) {
    if (value.HasMember("data")) {
        for (auto& a : value["data"].GetArray()) {
            data.push_back(a.GetInt64());
        }
    }
    std::string layerName = value["name"].GetString();
    isGround = "groundLayer" == layerName;
}

const std::vector<uint16_t> &TileLayer::getData() const {
    return data;
}

bool TileLayer::isGroundLayer() const {
    return isGround;
}

TileLayer::TileLayer(std::vector<uint16_t> data, bool isGround): data(std::move(data)), isGround(isGround) {}
