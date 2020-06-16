//
// Created by victorbelosevich on 14/06/20.
//

#ifndef ARGENTUM_JSONREADER_H
#define ARGENTUM_JSONREADER_H


#include <rapidjson/document.h>

class JsonReader {
public:
    JsonReader();

    virtual ~JsonReader();

    rapidjson::Document read(const std::string&);

};


#endif //ARGENTUM_JSONREADER_H
