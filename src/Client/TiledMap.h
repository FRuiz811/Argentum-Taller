//
// Created by victorbelosevich on 14/06/20.
//

#ifndef ARGENTUM_TILEDMAP_H
#define ARGENTUM_TILEDMAP_H


#include <vector>
#include <string>
#include "Layer.h"
#include "TileSet.h"

class TiledMap {
private:
    int height{};
    bool infinite{};
    std::vector<Layer> layers;
    int nextlayerid{};
    int nextobjectid{};
    std::string orientation;
    std::string renderorder;
    std::string tiledversion;
    int tileheight{};
    std::vector<TileSet> tilesets;
    int tilewidth{};
    std::string type;
    float version{};
    int width{};

public:
    TiledMap();

    ~TiledMap();

    int getHeight();
    bool isInfinite();
    std::vector<Layer> getLayers();
    int getNextLayerId();
    int getNextObjectId();
    std::string getOrientation();
    std::string getRenderOrder();
    std::string getTiledVersion();
    int getTileHeight();
    std::vector<TileSet> getTileSet();
    int getTileWidth();
    std::string getType();
    float getVersion();
    int getWidth();

    void setHeight(int height);

    void setInfinite(bool infinite);

    void setLayers(const std::vector<Layer> &layers);

    void setNextlayerid(int nextlayerid);

    void setNextobjectid(int nextobjectid);

    void setOrientation(const std::string &orientation);

    void setRenderorder(const std::string &renderorder);

    void setTiledversion(const std::string &tiledversion);

    void setTileheight(int tileheight);

    void setTilesets(const std::vector<TileSet> &tilesets);

    void setTilewidth(int tilewidth);

    void setType(const std::string &type);

    void setVersion(float version);

    void setWidth(int width);

};


#endif //ARGENTUM_TILEDMAP_H
