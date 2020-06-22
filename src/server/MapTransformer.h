#ifndef ARGENTUM_MAPTRANSFORMER_H
#define ARGENTUM_MAPTRANSFORMER_H


#include <rapidjson/document.h>
#include "../client/TiledMap.h"
#include <vector>

class MapTransformer {
public:
    MapTransformer();

    ~MapTransformer();

    static TiledMap transform(rapidjson::Document&);

};


#endif //ARGENTUM_MAPTRANSFORMER_H
