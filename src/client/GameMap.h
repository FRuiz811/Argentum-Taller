#ifndef ARGENTUM_GAMEMAP_H
#define ARGENTUM_GAMEMAP_H

#include "Tile.h"
#include "../common/TiledMap.h"
#include "Texture.h"
#include "Camera.h"
#include "../common/Chrono.h"
#include "ui/UI.h"
#include <vector>
#include <map>

class GameMap {
private:
    std::vector<Tile> tiles;
    std::vector<Tile> groundTiles;
    std::map<int, Texture> tileSetMap;
    SDL_Renderer& renderer;
    uint16_t rows, colums;
    uint16_t width, height;
    void _loadTileSets(const std::vector<TileSet>&, SDL_Renderer&);
public:
    explicit GameMap(const TiledMap&, SDL_Renderer&);

    virtual ~GameMap();

    void drawHighLayers(Camera& camera);
    void drawGround(Camera& camera);

    int getMapWidth() const;
    int getMapHeight() const;

};


#endif //ARGENTUM_GAMEMAP_H
