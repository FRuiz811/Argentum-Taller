#include <iostream>
#include "GameMap.h"

GameMap::GameMap(const TiledMap & tiledMap, SDL_Renderer& renderer) : renderer(renderer) {
    this->rows = tiledMap.getHeight();
    this->colums = tiledMap.getWidth();
    this->width = tiledMap.getWidth() * tiledMap.getTileWidth();
    this->height = tiledMap.getHeight() * tiledMap.getTileHeight();
    _loadTileSets(tiledMap.getTilesets(), renderer);

    uint8_t tileWidth = tiledMap.getTileWidth();
    uint8_t tileHeight = tiledMap.getTileHeight();

    for (auto& layer : tiledMap.getTileLayers()) {

        std::vector<uint16_t> layerData = layer.getData();

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
                if (layer.isGroundLayer()) {
                    groundTiles.push_back(aTile);
                } else {
                    tiles.push_back(aTile);
                }
            }
        }
    }

}
int GameMap::getMapHeight() {
    return this->height;
}

int GameMap::getMapWidth() {
    return this->width;
}


void GameMap::_loadTileSets(const std::vector<TileSet> &tileSets, SDL_Renderer &renderer) {
    SDL_Color textColor = {0x0, 0x0, 0x0};
    for  (auto& aTileSet : tileSets) {
        Texture aTexture(aTileSet.getImage(), renderer, textColor);
        tileSetMap.insert(std::pair<int, Texture>(aTileSet.getFirstgid(), std::move(aTexture)));
    }
}

void GameMap::drawHighLayers(Camera& camera) {
    for (Tile& tile: tiles) {
        tile.draw(renderer, camera);
    }
}

void GameMap::drawGround(Camera& camera) {
    for (Tile& tile: groundTiles) {
        tile.draw(renderer, camera);
    }
}

GameMap::~GameMap() = default;


