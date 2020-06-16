//
// Created by victorbelosevich on 14/06/20.
//

#include "Layer.h"

Layer::Layer() = default;

Layer::~Layer() = default;

Layer::Layer(rapidjson::Value & value) {
    if (value.HasMember("data")) {
        for (auto& a : value["data"].GetArray()) {
            data.push_back(a.GetInt64());
        }
    }

    if (value.HasMember("height")) {
        height = value["height"].GetInt();
    }

    id = value["id"].GetInt();

    if (value.HasMember("image")) {
        image = value["image"].GetString();
    }

    name = value["name"].GetString();
    opacity = value["opacity"].GetInt();
    type = value["type"].GetString();
    visible = value["visible"].GetBool();

    if (value.HasMember("width")) {
        width = value["width"].GetInt();
    }

    x = value["x"].GetInt();
    y = value["y"].GetInt();
}

const std::vector<int> &Layer::getData() const {
    return data;
}

int Layer::getHeight() const {
    return height;
}

int Layer::getId() const {
    return id;
}

const std::string &Layer::getImage() const {
    return image;
}

const std::string &Layer::getName() const {
    return name;
}

int Layer::getOpacity() const {
    return opacity;
}

const std::string &Layer::getType() const {
    return type;
}

bool Layer::isVisible() const {
    return visible;
}

int Layer::getWidth() const {
    return width;
}

int Layer::getX() const {
    return x;
}

int Layer::getY() const {
    return y;
}
