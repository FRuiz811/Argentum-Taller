//
// Created by victorbelosevich on 15/06/20.
//

#ifndef ARGENTUM_TILESET_H
#define ARGENTUM_TILESET_H


#include <string>
#include <rapidjson/document.h>

class TileSet {
private:
    int firstgid;
    int columns;
    std::string image;
    int imageHeight;
    int imageWidth;
    std::string name;
    int tilecount;
    int tileheight;
    int tilewidth;
    std::string type;

public:
    explicit TileSet(int, rapidjson::Document&&);

    virtual ~TileSet();

    int getFirstgid() const;

    const std::string &getImage() const;

    int getImageHeight() const;

    int getImageWidth() const;

    const std::string &getName() const;
};


#endif //ARGENTUM_TILESET_H
