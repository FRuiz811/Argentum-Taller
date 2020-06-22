#ifndef ARGENTUM_TILESET_H
#define ARGENTUM_TILESET_H


#include <string>
#include <rapidjson/document.h>

class TileSet {
private:
    int firstgid;
    std::string image;
    int imageHeight;
    int imageWidth;
    std::string name;

public:
    explicit TileSet(rapidjson::Value&);

    virtual ~TileSet();

    int getFirstgid() const;

    const std::string &getImage() const;

    int getImageHeight() const;

    int getImageWidth() const;

    const std::string &getName() const;
};


#endif //ARGENTUM_TILESET_H
