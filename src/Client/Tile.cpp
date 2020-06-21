#include "Tile.h"
#include <iostream>

Tile::Tile(int x, int y, int tx, int ty,
        int width, int height, Texture &texture) :
        x(x), y(y), tx(tx), ty(ty),
        width(width), height(height),
        texture(texture), position(tx,ty) {}

void Tile::draw(SDL_Renderer &renderer, Camera& camera) {
    src.w = width;
    src.h = height;
    src.x = tx;
    src.y = ty;
    destinyAdjust(camera);
    texture.render(src, dest);
}

void Tile::destinyAdjust(Camera& camera) {
    this->dest.w = width*camera.getScale();
    this->dest.h = height*camera.getScale();
    this->dest.x = (x - camera.getCameraPosition().x)-(width/2)*camera.getScale();
    this->dest.y = (y - camera.getCameraPosition().y)-(height/2)*camera.getScale();

}

Tile::~Tile() = default;
