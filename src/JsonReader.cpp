#include <fstream>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include "JsonReader.h"
#include <rapidjson/error/en.h>

JsonReader::JsonReader() = default;

JsonReader::~JsonReader() = default;

rapidjson::Document JsonReader::read(const std::string & filename) {
    std::ifstream file(filename);
    rapidjson::IStreamWrapper isw(file);
    rapidjson::Document json;
    json.ParseStream(isw);
    if (json.HasParseError()) {
        std::cout << "There are some problems with parsing: " << rapidjson::GetParseError_En(json.GetParseError()) <<std::endl;
        return nullptr;
    }
    return std::move(json);
}
