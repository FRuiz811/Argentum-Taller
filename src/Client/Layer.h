//
// Created by victorbelosevich on 14/06/20.
//

#ifndef ARGENTUM_LAYER_H
#define ARGENTUM_LAYER_H

#include <vector>
#include <string>
#include "rapidjson/document.h"

class Layer {
private:
    std::vector<int> data;
    int height{};
    int id{};
    std::string image;
    std::string name;
    int opacity{};
    std::string type;
    bool visible{};
    int width{};
    int x{};
    int y{};

public:
    Layer();
    explicit Layer(rapidjson::Value&);

    virtual ~Layer();

    const std::vector<int> &getData() const;

    int getHeight() const;

    int getId() const;

    const std::string &getImage() const;

    const std::string &getName() const;

    int getOpacity() const;

    const std::string &getType() const;

    bool isVisible() const;

    int getWidth() const;

    int getX() const;

    int getY() const;

};


#endif //ARGENTUM_LAYER_H
