#ifndef ARGENTUM_TILESET_H
#define ARGENTUM_TILESET_H

#include <string>
#include <rapidjson/document.h>

class TileSet {
private:
    uint16_t firstgid;
    std::string image;
    uint8_t id;

public:
    explicit TileSet(rapidjson::Value&, uint8_t id);
    TileSet(uint16_t firstGid, uint8_t id);

    virtual ~TileSet();

    int getFirstgid() const;

    const std::string &getImage() const;

    uint8_t getId() const;
};


#endif //ARGENTUM_TILESET_H
