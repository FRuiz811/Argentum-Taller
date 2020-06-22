#include <fstream>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include "JsonReader.h"
#include "client/Exception.h"

JsonReader::JsonReader() = default;

JsonReader::~JsonReader() = default;

rapidjson::Document JsonReader::read(const std::string & filename) {
    std::ifstream file(filename);
    rapidjson::IStreamWrapper isw(file);
    rapidjson::Document json;
    json.ParseStream(isw);
    if (json.HasParseError()) {
        throw Exception("There are some problems with parsing", json.GetParseError());
    }
    return json;
}
