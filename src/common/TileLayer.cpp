#include "TileLayer.h"

TileLayer::TileLayer() = default;

TileLayer::~TileLayer() = default;

TileLayer::TileLayer(rapidjson::Value & value) {
    if (value.HasMember("data")) {
        for (auto& a : value["data"].GetArray()) {
            data.push_back(a.GetInt64());
        }
    }

    if (value.HasMember("height")) {
        height = value["height"].GetInt();
    }

    name = value["name"].GetString();
    type = value["type"].GetString();

    if (value.HasMember("width")) {
        width = value["width"].GetInt();
    }

    x = value["x"].GetInt();
    y = value["y"].GetInt();
}

const std::vector<int> &TileLayer::getData() const {
    return data;
}
