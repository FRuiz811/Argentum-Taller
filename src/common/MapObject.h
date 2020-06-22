#ifndef ARGENTUM_TALLER_MAPOBJECT_H
#define ARGENTUM_TALLER_MAPOBJECT_H

#include <rapidjson/document.h>
#include "Position.h"

class MapObject {
private:
    Position position;
   unsigned int id{};
public:
    explicit MapObject(rapidjson::Value &value);

//    MapObject(MapObject&& other) noexcept;
//    MapObject& operator=(MapObject&& other) noexcept;

    ~MapObject();

    const Position &getPosition() const;
};


#endif //ARGENTUM_TALLER_MAPOBJECT_H
