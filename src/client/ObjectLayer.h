#ifndef ARGENTUM_TALLER_OBJECTLAYER_H
#define ARGENTUM_TALLER_OBJECTLAYER_H


#include <string>
#include <vector>
#include <rapidjson/pointer.h>
#include "MapObject.h"

class ObjectLayer {
private:
    std::string name;
    std::vector<MapObject> objects;
    std::string type;

public:
    ObjectLayer(rapidjson::Value&);

    ~ObjectLayer();

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<MapObject> &getObjects() const;

    void setObjects(const std::vector<MapObject> &objects);
};


#endif //ARGENTUM_TALLER_OBJECTLAYER_H
