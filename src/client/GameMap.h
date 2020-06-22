#ifndef ARGENTUM_GAMEMAP_H
#define ARGENTUM_GAMEMAP_H

#include "Tile.h"
#include "TiledMap.h"
#include "Texture.h"
#include <vector>
#include <map>

class GameMap {
private:
    std::vector<Tile> tiles;
    std::map<int, Texture> tileSetMap;
    void _loadTileSets(const std::vector<TileSet>&, SDL_Renderer&);
public:
    explicit GameMap(const TiledMap&, SDL_Renderer&);

    virtual ~GameMap();

    void draw(SDL_Renderer&);

};


#endif //ARGENTUM_GAMEMAP_H
