//
// Created by victorbelosevich on 14/06/20.
//

#ifndef ARGENTUM_TILESETMAP_H
#define ARGENTUM_TILESETMAP_H


#include <string>
#include <rapidjson/document.h>

class TileSetMap {
private:
    int firstgid;
    std::string source;

public:
    explicit TileSetMap(rapidjson::Value & value);

    ~TileSetMap();

    int getFirstGId();
    std::string getSource();

};


#endif //ARGENTUM_TILESETMAP_H
