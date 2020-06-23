#ifndef ARGENTUM_TALLER_STATICOBJECT_H
#define ARGENTUM_TALLER_STATICOBJECT_H

#include <rapidjson/document.h>
#include "Position.h"

class StaticObject {
private:
    Position position;
    unsigned int id{};
public:
    explicit StaticObject(rapidjson::Value &value);

    ~StaticObject();

    const Position &getPosition() const;
};


#endif //ARGENTUM_TALLER_STATICOBJECT_H
