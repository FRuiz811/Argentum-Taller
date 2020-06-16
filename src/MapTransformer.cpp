//
// Created by victorbelosevich on 14/06/20.
//

#include <algorithm>
#include "MapTransformer.h"
#include "JsonReader.h"


MapTransformer::MapTransformer() = default;

MapTransformer::~MapTransformer() = default;

rapidjson::Document _getTileSet(rapidjson::Value& value) {
    std::string filename = value["source"].GetString();
    filename = "json/" + filename.substr(0, filename.size() - 4) + ".json";
    JsonReader jsonReader;
    return jsonReader.read(filename);
}

TiledMap MapTransformer::transform(rapidjson::Document & json) {
    TiledMap tiledMap;
    tiledMap.setHeight(json["height"].GetInt());
    tiledMap.setInfinite(json["infinite"].GetBool());

    rapidjson::Value::Array layersA = json["layers"].GetArray();
    std::vector<Layer> layers;
    for (size_t i = 0; i < layersA.Capacity(); i++) {
        Layer layer(layersA[i]);
        layers.push_back(layer);
    }
    tiledMap.setLayers(layers);

    tiledMap.setNextlayerid(json["nextlayerid"].GetInt());
    tiledMap.setNextobjectid(json["nextobjectid"].GetInt());
    tiledMap.setOrientation(json["orientation"].GetString());
    tiledMap.setRenderorder(json["renderorder"].GetString());
    tiledMap.setTiledversion(json["tiledversion"].GetString());
    tiledMap.setTileheight(json["tileheight"].GetInt());



    rapidjson::Value::Array tileSetArray = json["tilesets"].GetArray();
    std::vector<TileSet> tilesets;
    for (size_t i = 0; i < tileSetArray.Capacity(); i++) {
        TileSet tileset(tileSetArray[i]["firstgid"].GetInt(), _getTileSet(tileSetArray[i]));
        tilesets.push_back(tileset);
    }
    tiledMap.setTilesets(tilesets);

    tiledMap.setTilewidth(json["tilewidth"].GetInt());
    tiledMap.setType(json["type"].GetString());
    tiledMap.setVersion(json["version"].GetFloat());
    tiledMap.setWidth(json["width"].GetInt());
    return tiledMap;
}


