#ifndef ARGENTUM_TILE_H
#define ARGENTUM_TILE_H


#include "Texture.h"
#include "Camera.h"
#include "../common/Point.h"

class Tile {
private:
    int x;
    int y;
    int tx;
    int ty;
    int width;
    int height;
    Texture& texture;
    SDL_Rect src, dest;
public:
    Tile(int x, int y, int tx, int ty, int width, int height, Texture &texture);

    virtual ~Tile();

    void destinyAdjust(Camera& camera);

    void draw(SDL_Renderer&, Camera& camera);

};


#endif //ARGENTUM_TILE_H
