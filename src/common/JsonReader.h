#ifndef ARGENTUM_JSONREADER_H
#define ARGENTUM_JSONREADER_H


#include <rapidjson/document.h>

class JsonReader {
public:
    JsonReader();

    virtual ~JsonReader();

    static rapidjson::Document read(const std::string&);

};


#endif //ARGENTUM_JSONREADER_H
