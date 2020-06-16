#include "Tile.h"

Tile::Tile(int x, int y, int tx, int ty,
        int width, int height, Texture &texture) :
        x(x), y(y), tx(tx), ty(ty),
        width(width), height(height),
        texture(texture) {}

void Tile::draw(SDL_Renderer &renderer) {
    SDL_Rect src;
    src.w = width;
    src.h = height;
    src.x = tx;
    src.y = ty;
    SDL_Rect dest;
    dest.w = width;
    dest.h = height;
    dest.x = x;
    dest.y = y;
    texture.render(src, dest);
}

Tile::~Tile() = default;
