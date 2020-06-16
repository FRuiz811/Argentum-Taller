//
// Created by victorbelosevich on 14/06/20.
//

#include "TileSetMap.h"

TileSetMap::~TileSetMap() = default;

int TileSetMap::getFirstGId() {
    return firstgid;
}

std::string TileSetMap::getSource() {
    return source;
}

TileSetMap::TileSetMap(rapidjson::Value &value) {
    firstgid = value["firstgid"].GetInt();
    source = value["source"].GetString();
}
