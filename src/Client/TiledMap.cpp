//
// Created by victorbelosevich on 14/06/20.
//

#include "TiledMap.h"

TiledMap::TiledMap() = default;

TiledMap::~TiledMap() = default;

int TiledMap::getHeight() {
    return height;
}

bool TiledMap::isInfinite() {
    return infinite;
}

std::vector<Layer> TiledMap::getLayers() {
    return layers;
}

int TiledMap::getNextLayerId() {
    return nextlayerid;
}

int TiledMap::getNextObjectId() {
    return nextobjectid;
}

std::string TiledMap::getOrientation() {
    return orientation;
}

std::string TiledMap::getRenderOrder() {
    return renderorder;
}

std::string TiledMap::getTiledVersion() {
    return tiledversion;
}

int TiledMap::getTileHeight() {
    return tileheight;
}

std::vector<TileSet> TiledMap::getTileSet() {
    return tilesets;
}

int TiledMap::getTileWidth() {
    return tilewidth;
}

std::string TiledMap::getType() {
    return type;
}

float TiledMap::getVersion() {
    return version;
}

int TiledMap::getWidth() {
    return width;
}

int TiledMap::getMapHeight() {
    return this->height*this->tileheight;
}

int TiledMap::getMapWidth() {
    return this->width*this->tilewidth;
}

void TiledMap::setHeight(int height) {
    TiledMap::height = height;
}

void TiledMap::setInfinite(bool infinite) {
    TiledMap::infinite = infinite;
}

void TiledMap::setLayers(const std::vector<Layer> &layers) {
    TiledMap::layers = layers;
}

void TiledMap::setNextlayerid(int nextlayerid) {
    TiledMap::nextlayerid = nextlayerid;
}

void TiledMap::setNextobjectid(int nextobjectid) {
    TiledMap::nextobjectid = nextobjectid;
}

void TiledMap::setOrientation(const std::string &orientation) {
    TiledMap::orientation = orientation;
}

void TiledMap::setRenderorder(const std::string &renderorder) {
    TiledMap::renderorder = renderorder;
}

void TiledMap::setTiledversion(const std::string &tiledversion) {
    TiledMap::tiledversion = tiledversion;
}

void TiledMap::setTileheight(int tileheight) {
    TiledMap::tileheight = tileheight;
}

void TiledMap::setTilesets(const std::vector<TileSet> &tilesets) {
    TiledMap::tilesets = tilesets;
}

void TiledMap::setTilewidth(int tilewidth) {
    TiledMap::tilewidth = tilewidth;
}

void TiledMap::setType(const std::string &type) {
    TiledMap::type = type;
}

void TiledMap::setVersion(float version) {
    TiledMap::version = version;
}

void TiledMap::setWidth(int width) {
    TiledMap::width = width;
}
