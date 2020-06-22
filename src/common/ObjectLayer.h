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
    explicit ObjectLayer(rapidjson::Value&);

//    ObjectLayer(ObjectLayer&& other) noexcept ;
//    ObjectLayer& operator=(ObjectLayer&& other) noexcept;

    ~ObjectLayer();

    const std::string &getName() const;

    std::vector<MapObject>&& getObjects();
};


#endif //ARGENTUM_TALLER_OBJECTLAYER_H
