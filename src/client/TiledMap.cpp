#include "TiledMap.h"

TiledMap::TiledMap() = default;

TiledMap::~TiledMap() = default;

int TiledMap::getHeight() const {
    return height;
}

void TiledMap::setHeight(int aHeight) {
    TiledMap::height = aHeight;
}

const std::vector<TileLayer> &TiledMap::getTileLayers() const {
    return tileLayers;
}

void TiledMap::setTileLayers(const std::vector<TileLayer> &tileLayers) {
    TiledMap::tileLayers = tileLayers;
}

const std::vector<ObjectLayer> &TiledMap::getObjectLayers() const {
    return objectLayers;
}

void TiledMap::setObjectLayers(const std::vector<ObjectLayer> &objectLayers) {
    TiledMap::objectLayers = objectLayers;
}

int TiledMap::getTileheight() const {
    return tileHeight;
}

void TiledMap::setTileheight(int tileheight) {
    TiledMap::tileHeight = tileheight;
}

const std::vector<TileSet> &TiledMap::getTilesets() const {
    return tilesets;
}

void TiledMap::setTilesets(const std::vector<TileSet> &tilesets) {
    TiledMap::tilesets = tilesets;
}

int TiledMap::getTilewidth() const {
    return tileWidth;
}

void TiledMap::setTilewidth(int tilewidth) {
    TiledMap::tileWidth = tilewidth;
}

int TiledMap::getWidth() const {
    return width;
}

void TiledMap::setWidth(int width) {
    TiledMap::width = width;
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


