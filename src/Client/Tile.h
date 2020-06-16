//
// Created by victorbelosevich on 15/06/20.
//

#ifndef ARGENTUM_TILE_H
#define ARGENTUM_TILE_H


#include "Texture.h"

class Tile {
private:
    int x;
    int y;
    int tx;
    int ty;
    int width;
    int height;
    Texture& texture;
public:
    Tile(int x, int y, int tx, int ty, int width, int height, Texture &texture);

    virtual ~Tile();

    void draw(SDL_Renderer&);

};


#endif //ARGENTUM_TILE_H
