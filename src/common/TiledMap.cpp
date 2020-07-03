#include "TiledMap.h"

TiledMap::TiledMap(rapidjson::Document & json) {
    width = json["width"].GetInt();
    height = json["height"].GetInt();
    tileWidth = json["tilewidth"].GetInt();
    tileHeight = json["tileheight"].GetInt();

    rapidjson::Value::Array layers = json["layers"].GetArray();
    for (auto &aLayer : layers) {
        std::string type = aLayer["type"].GetString();
        if ("tilelayer" == type) {
            TileLayer tileSet(aLayer);
            tileLayers.push_back(tileSet);
        } else if ("objectgroup" == type) {
            ObjectLayer objectLayer(aLayer);
            objectLayers.push_back(objectLayer);
        }
    }
    uint8_t idCounter = 0;
    rapidjson::Value::Array tileSetArray = json["tilesets"].GetArray();
    for (auto &aTileSet : tileSetArray) {
        TileSet tileset(aTileSet, ++idCounter);
        tilesets.push_back(tileset);
    }
}

TiledMap::TiledMap() = default;

const std::vector<TileLayer> &TiledMap::getTileLayers() const {
    return tileLayers;
}

std::vector<ObjectLayer> TiledMap::getObjectLayers() {
    return objectLayers;
}

const std::vector<TileSet> &TiledMap::getTilesets() const {
    return tilesets;
}

TiledMap::TiledMap(TiledMap &&other) noexcept {
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(tileHeight, other.tileHeight);
    std::swap(tileWidth, other.tileWidth);
    std::swap(tileLayers, other.tileLayers);
    std::swap(objectLayers, other.objectLayers);
    std::swap(tilesets, other.tilesets);
}

TiledMap &TiledMap::operator=(TiledMap &&other) noexcept {
    if(this == &other) {
        return *this;
    }
    std::swap(height, other.height);
    std::swap(width, other.width);
    std::swap(tileHeight, other.tileHeight);
    std::swap(tileWidth, other.tileWidth);
    std::swap(tileLayers, other.tileLayers);
    std::swap(objectLayers, other.objectLayers);
    std::swap(tilesets, other.tilesets);
    return *this;
}

uint16_t TiledMap::getHeight() const {
    return height;
}

uint16_t TiledMap::getWidth() const {
    return width;
}

uint8_t TiledMap::getTileHeight() const {
    return tileHeight;
}

uint8_t TiledMap::getTileWidth() const {
    return tileWidth;
}

TiledMap::TiledMap(uint16_t width, uint16_t height, uint8_t tileWidth, uint8_t tileHeight,
                   const std::vector<TileLayer> &tileLayers, const std::vector<TileSet> &tilesets) :
                   width(width), height(height), tileWidth(tileWidth), tileHeight(tileHeight),
                   tileLayers(tileLayers), tilesets(tilesets) {}

TiledMap::~TiledMap() = default;