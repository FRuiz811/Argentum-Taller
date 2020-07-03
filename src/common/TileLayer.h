#ifndef ARGENTUM_LAYER_H
#define ARGENTUM_LAYER_H

#include <vector>
#include <string>
#include "rapidjson/document.h"

class TileLayer {
private:
    std::vector<uint16_t> data;
    bool isGround;

public:
    TileLayer();
    explicit TileLayer(rapidjson::Value&);
    TileLayer(std::vector<uint16_t> data, bool isGround);

    virtual ~TileLayer();

    const std::vector<uint16_t> &getData() const;

    bool isGroundLayer() const;
};


#endif //ARGENTUM_LAYER_H
