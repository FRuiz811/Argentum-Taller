#include <fstream>
#include <rapidjson/istreamwrapper.h>
#include "JsonReader.h"
#include <rapidjson/error/en.h>
#include "Exception.h"

JsonReader::JsonReader() = default;

JsonReader::~JsonReader() = default;

rapidjson::Document JsonReader::read(const std::string & filename) {
    std::ifstream file(filename);
    rapidjson::IStreamWrapper isw(file);
    rapidjson::Document json;
    json.ParseStream(isw);
    if (json.HasParseError()) {
        throw Exception("There are some problems with parsing", rapidjson::GetParseError_En(json.GetParseError()));
    }
    return json;
}
