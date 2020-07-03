#include "TileSet.h"

TileSet::TileSet(rapidjson::Value & tilesetDoc, uint8_t id) {
    firstgid = tilesetDoc["firstgid"].GetInt();
    image = tilesetDoc["image"].GetString();
    id = id;
}

int TileSet::getFirstgid() const {
    return firstgid;
}

const std::string &TileSet::getImage() const {
    return image;
}

uint8_t TileSet::getId() const {
    return id;
}

TileSet::TileSet(uint16_t firstGid, uint8_t id): firstgid(firstGid), id(id) {
    image = "assets/img/map/" + std::to_string(id) + ".png";
}

TileSet::~TileSet() = default;
