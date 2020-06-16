//
// Created by victorbelosevich on 15/06/20.
//

#ifndef ARGENTUM_GAMEMAP_H
#define ARGENTUM_GAMEMAP_H


#include <vector>
#include "Tile.h"
#include "TiledMap.h"
#include "Texture.h"
#import <map>



class GameMap {
private:
    std::vector<Tile> tiles;
    std::map<int, Texture> tileSetMap;
    void _loadTileSets(const std::vector<TileSet>&, SDL_Renderer&);
public:
    explicit GameMap(TiledMap&, SDL_Renderer&);

    virtual ~GameMap();

    void draw(SDL_Renderer&);

};


#endif //ARGENTUM_GAMEMAP_H
