#ifndef ARGENTUM_TALLER_STATICOBJECT_H
#define ARGENTUM_TALLER_STATICOBJECT_H

#include <rapidjson/document.h>
#include "Position.h"

class StaticObject {
private:
    Position position;
    std::string name;

public:
    explicit StaticObject(rapidjson::Value &value);

    ~StaticObject();

    const Position &getPosition() const;

    const std::string &getName() const;
};


#endif //ARGENTUM_TALLER_STATICOBJECT_H
