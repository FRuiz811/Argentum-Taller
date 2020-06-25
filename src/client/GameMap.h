#ifndef ARGENTUM_GAMEMAP_H
#define ARGENTUM_GAMEMAP_H

#include "Tile.h"
#include "../common/TiledMap.h"
#include "Texture.h"
#include "Camera.h"
#include <vector>
#include <map>

class GameMap {
private:
    std::vector<Tile> tiles;
    std::vector<Tile> groundTiles;
    std::map<int, Texture> tileSetMap;
    SDL_Renderer& renderer;
    int rows, colums;
    int width, height;
    void _loadTileSets(const std::vector<TileSet>&, SDL_Renderer&);
public:
    explicit GameMap(const TiledMap&, SDL_Renderer&);

    virtual ~GameMap();

    void drawHighLayers(Camera& camera);
    void drawGround(Camera& camera);

    int getMapWidth();
    int getMapHeight();

};


#endif //ARGENTUM_GAMEMAP_H
