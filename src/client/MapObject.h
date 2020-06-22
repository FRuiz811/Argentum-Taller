#ifndef ARGENTUM_TALLER_MAPOBJECT_H
#define ARGENTUM_TALLER_MAPOBJECT_H

#include <rapidjson/document.h>
#include "../server/Position.h"

class MapObject {
private:
   Position position;
   unsigned int id;
public:
    MapObject(rapidjson::Value &value);

    MapObject(MapObject&& other);

    ~MapObject();

    const Position &getPosition() const;
};


#endif //ARGENTUM_TALLER_MAPOBJECT_H
