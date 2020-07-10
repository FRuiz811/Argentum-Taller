#ifndef ARGENTUM_TALLER_STATICOBJECT_H
#define ARGENTUM_TALLER_STATICOBJECT_H

#include <rapidjson/document.h>
#include "Point.h"

class StaticObject {
private:
    Point topLeft;
    Point topRight;
    Point bottomLeft;
    Point bottomRight;
    std::string name;

public:
    explicit StaticObject(rapidjson::Value &value);

    ~StaticObject();

    const Point &getTopLeft() const;

    const Point &getTopRight() const;

    const Point &getBottomLeft() const;

    const Point &getBottomRight() const;

    const std::string &getName() const;
};


#endif //ARGENTUM_TALLER_STATICOBJECT_H
