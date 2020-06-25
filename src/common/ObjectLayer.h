#ifndef ARGENTUM_TALLER_OBJECTLAYER_H
#define ARGENTUM_TALLER_OBJECTLAYER_H

#include <string>
#include <vector>
#include <rapidjson/pointer.h>
#include "StaticObject.h"

class ObjectLayer {
private:
    std::string name;
    std::vector<StaticObject> objects;
    std::string type;

public:
    explicit ObjectLayer(rapidjson::Value&);

    ~ObjectLayer();

    const std::string &getName() const;

    std::vector<StaticObject> getObjects();
};


#endif //ARGENTUM_TALLER_OBJECTLAYER_H
