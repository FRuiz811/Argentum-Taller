#include "MapTransformer.h"


MapTransformer::MapTransformer() = default;

MapTransformer::~MapTransformer() = default;

void addLayers(rapidjson::Value::Array& layers,
        std::vector<TileLayer>& tileLayers,
        std::vector<ObjectLayer> objectsLayers) {
    for (auto &aLayer : layers) {
        std::string type = aLayer["type"].GetString();
        if ("tileLayer" == type) {
            TileLayer tileSet(aLayer);
            tileLayers.push_back(tileSet);
        } else {
            ObjectLayer objectLayer(aLayer);
            objectsLayers.push_back(objectLayer);
        }
    }
}

TiledMap MapTransformer::transform(rapidjson::Document & json) {
    TiledMap tiledMap;
    tiledMap.setHeight(json["height"].GetInt());

    rapidjson::Value::Array layers = json["layers"].GetArray();
    std::vector<TileLayer> tileLayers;
    std::vector<ObjectLayer> objectLayers;
    addLayers(layers, tileLayers, objectLayers);

    tiledMap.setTileLayers(tileLayers);
    tiledMap.setTileheight(json["tileHeight"].GetInt());

    rapidjson::Value::Array tileSetArray = json["tilesets"].GetArray();
    std::vector<TileSet> tilesets;
    for (auto &aTileSet : tileSetArray) {
        TileSet tileset(aTileSet);
        tilesets.push_back(tileset);
    }
    tiledMap.setTilesets(tilesets);

    tiledMap.setTilewidth(json["tileWidth"].GetInt());
    tiledMap.setWidth(json["width"].GetInt());
    return tiledMap;
}


