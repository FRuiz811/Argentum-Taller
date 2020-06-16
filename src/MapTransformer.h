//
// Created by victorbelosevich on 14/06/20.
//

#ifndef ARGENTUM_MAPTRANSFORMER_H
#define ARGENTUM_MAPTRANSFORMER_H


#include <rapidjson/document.h>
#include "Client/TiledMap.h"
#include <vector>

class MapTransformer {
public:
    MapTransformer();

    ~MapTransformer();

    TiledMap transform(rapidjson::Document&);

};


#endif //ARGENTUM_MAPTRANSFORMER_H
