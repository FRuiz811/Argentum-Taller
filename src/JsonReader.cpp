//
// Created by victorbelosevich on 14/06/20.
//

#include <fstream>
#include <rapidjson/istreamwrapper.h>
#include <iostream>
#include "JsonReader.h"

JsonReader::JsonReader() {}

JsonReader::~JsonReader() {

}

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
