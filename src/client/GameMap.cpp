#include <iostream>
#include "GameMap.h"

GameMap::GameMap(const TiledMap& tiledMap, SDL_Renderer& renderer) {
    int rows = tiledMap.getHeight();
    int colums = tiledMap.getWidth();
    _loadTileSets(tiledMap.getTilesets(), renderer);

    int tileWidth = tiledMap.getTilewidth();
    int tileHeight = tiledMap.getTileheight();

    for (auto& layer : tiledMap.getTileLayers()) {

        std::vector<int> layerData = layer.getData();

        for (int y = 0; y < rows; ++y) {
            for (int x = 0; x < colums; ++x) {
                int tileIndex = x + (y * colums);
                int curGid = layerData[tileIndex];

                if (curGid == 0) {
                    continue;
                }

                int tileSetGid = -1;
                for (auto& ts : tileSetMap) {
                    if (ts.first <= curGid ) {
                        tileSetGid = ts.first;
                    }
                }

                if (tileSetGid == -1) {
                    continue;
                }
                Texture& loadTexture = tileSetMap.at(tileSetGid);

                curGid -= tileSetGid;

                int regionX = (curGid % (loadTexture.getWidth() / tileWidth)) * tileWidth;
                int regionY = (curGid / (loadTexture.getWidth() / tileHeight)) * tileHeight;

                int xPos = x * tileWidth;
                int yPos = y * tileHeight;

                Tile aTile(xPos, yPos, regionX, regionY, tileWidth, tileHeight, loadTexture);
                tiles.push_back(aTile);
            }
        }
    }

}

void GameMap::_loadTileSets(const std::vector<TileSet> &tileSets, SDL_Renderer &renderer) {
    SDL_Color textColor = {0x0, 0x0, 0x0};
    for  (auto& aTileSet : tileSets) {
        Texture aTexture(aTileSet.getImage(), renderer, textColor);
        tileSetMap.insert(std::pair<int, Texture>(aTileSet.getFirstgid(), std::move(aTexture)));
    }
}

void GameMap::draw(SDL_Renderer & renderer) {
    for (Tile& tile: tiles) {
        tile.draw(renderer);
    }
}

GameMap::~GameMap() = default;


