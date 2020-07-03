#ifndef ARGENTUM_TILEDMAP_H
#define ARGENTUM_TILEDMAP_H


#include <vector>
#include <string>
#include "TileLayer.h"
#include "TileSet.h"
#include "ObjectLayer.h"

class TiledMap {
private:
    uint16_t width{};
    uint16_t height{};
    uint8_t tileWidth{};
    uint8_t tileHeight{};
    std::vector<TileLayer> tileLayers;
    std::vector<ObjectLayer> objectLayers;
    std::vector<TileSet> tilesets;
public:
    TiledMap();
    explicit TiledMap(rapidjson::Document & json);

    TiledMap(uint16_t width, uint16_t height, uint8_t tileWidth, uint8_t tileHeight,
             const std::vector<TileLayer> &tileLayers, const std::vector<TileSet> &tilesets);

    ~TiledMap();

    TiledMap(TiledMap&& other) noexcept ;
    TiledMap& operator=(TiledMap&& other) noexcept ;

    std::vector<ObjectLayer> getObjectLayers();

    const std::vector<TileLayer> &getTileLayers() const;

    const std::vector<TileSet> &getTilesets() const;

    uint16_t getHeight() const;

    uint16_t getWidth() const;

    uint8_t getTileHeight() const;

    uint8_t getTileWidth() const;
};


#endif //ARGENTUM_TILEDMAP_H
