//
// Created by victorbelosevich on 15/06/20.
//

#include "TileSet.h"

TileSet::TileSet(int gid, rapidjson::Document&& tilesetDoc) {
    firstgid = gid;
    columns = tilesetDoc["columns"].GetInt();
    image = tilesetDoc["image"].GetString();
    imageHeight = tilesetDoc["imageheight"].GetInt();
    imageWidth = tilesetDoc["imagewidth"].GetInt();
    name = tilesetDoc["name"].GetString();
    tilecount = tilesetDoc["tilecount"].GetInt();
    tileheight = tilesetDoc["tileheight"].GetInt();
    tilewidth = tilesetDoc["tilewidth"].GetInt();
    type = tilesetDoc["type"].GetString();
}

int TileSet::getFirstgid() const {
    return firstgid;
}

const std::string &TileSet::getImage() const {
    return image;
}

int TileSet::getImageHeight() const {
    return imageHeight;
}

int TileSet::getImageWidth() const {
    return imageWidth;
}

const std::string &TileSet::getName() const {
    return name;
}

TileSet::~TileSet() = default;


