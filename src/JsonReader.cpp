#include <fstream>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include "JsonReader.h"

JsonReader::JsonReader() = default;

JsonReader::~JsonReader() = default;

rapidjson::Document JsonReader::read(const std::string & filename) {
    std::ifstream file(filename);
    rapidjson::IStreamWrapper isw(file);
    rapidjson::Document json;
    json.ParseStream(isw);
    if (json.HasParseError()) {
        std::cout << "There are some problems with parsing" << std::endl;
        return nullptr;
    }
    return std::move(json);
}
