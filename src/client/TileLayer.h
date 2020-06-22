#ifndef ARGENTUM_LAYER_H
#define ARGENTUM_LAYER_H

#include <vector>
#include <string>
#include "rapidjson/document.h"

class TileLayer {
private:
    std::vector<int> data;
    int height;
    std::string name;
    std::string type;
    int width;
    int x;
    int y;

public:
    TileLayer();
    explicit TileLayer(rapidjson::Value&);

    virtual ~TileLayer();

    const std::vector<int> &getData() const;
};


#endif //ARGENTUM_LAYER_H
