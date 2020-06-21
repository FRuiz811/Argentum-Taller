#ifndef ARGENTUM_GAMEMAP_H
#define ARGENTUM_GAMEMAP_H

#include "Tile.h"
#include "TiledMap.h"
#include "Texture.h"
#include "Camera.h"
#include <vector>
#include <map>

class GameMap {
private:
    std::vector<Tile> tiles;
    std::map<int, Texture> tileSetMap;
    SDL_Renderer& renderer;
    int rows, colums;
    void _loadTileSets(const std::vector<TileSet>&, SDL_Renderer&);
public:
    explicit GameMap(TiledMap&, SDL_Renderer&);

    virtual ~GameMap();

    void draw(Camera& camera);

};


#endif //ARGENTUM_GAMEMAP_H
