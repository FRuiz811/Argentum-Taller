#ifndef ARGENTUM_TILEDMAP_H
#define ARGENTUM_TILEDMAP_H


#include <vector>
#include <string>
#include "TileLayer.h"
#include "TileSet.h"
#include "ObjectLayer.h"

class TiledMap {
private:
    int height;
    int width;
    int tileHeight;
    int tileWidth;
    std::vector<TileLayer> tileLayers;
    std::vector<ObjectLayer> objectLayers;
    std::vector<TileSet> tilesets;
public:
    TiledMap();

    ~TiledMap();

    TiledMap(TiledMap&& other) noexcept ;
    TiledMap& operator=(TiledMap&& other) noexcept ;

    int getHeight() const;

    void setObjectLayers(const std::vector<ObjectLayer> &objectLayers);

    void setHeight(int aHeight);

    const std::vector<TileLayer> &getTileLayers() const;

    void setTileLayers(const std::vector<TileLayer> &tileLayers);

    std::vector<ObjectLayer> getObjectLayers();

    int getTileheight() const;

    void setTileheight(int tileheight);

    const std::vector<TileSet> &getTilesets() const;

    void setTilesets(const std::vector<TileSet> &tilesets);

    int getTilewidth() const;

    void setTilewidth(int tilewidth);

    int getWidth() const;

    void setWidth(int width);

};


#endif //ARGENTUM_TILEDMAP_H
