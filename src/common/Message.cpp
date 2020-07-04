#include "Message.h"

#include <utility>
#include "Exception.h"


Message::~Message() = default;

Message::Message() = default;

uint8_t Message::getType() const {
    return type;
}

uint32_t Message::read(uint8_t bytesToRead) {

    return *(data.data() + pos + bytesToRead);
}

Message::Message(std::vector<uint8_t>& data, uint32_t length, uint8_t type) :
data(std::move(data)), length(length), type(type) {}

void Message::clear() {
    pos = 0;
}

uint32_t conversorTo32(const uint8_t* value) {
    uint8_t temp[4];
    uint32_t* temp32;
    for (int j = 0; j < 4; j++) {
        temp[j] = value[j];
    }
    temp32 = (uint32_t*) temp;
    return *temp32;
}

uint16_t conversorTo16(const uint8_t* value) {
    uint8_t temp[4];
    uint16_t* temp16;
    for (int j = 0; j < 2; j++) {
        temp[j] = value[j];
    }
    temp16 = (uint16_t*) temp;
    return *temp16;
}

uint8_t Message::read8() {
    if (pos >= length) {
        throw Exception("Se quiere ingresar a una posicion no valida");
    }
    uint8_t value = *(data.data() + pos);
    pos++;
    return value;
}

uint16_t Message::read16() {
    if (pos + 2 >= length) {
        throw Exception("Se quiere ingresar a una posicion no valida");
    }
    uint16_t value = conversorTo16(data.data() + pos);
    pos += 2;
    return value;
}

uint32_t Message::read32() {
    if (pos + 4 >= length) {
        throw Exception("Se quiere ingresar a una posicion no valida");
    }
    uint32_t value = conversorTo32(data.data() + pos);
    pos += 4;
    return value;
}

const std::vector<uint8_t> &Message::getData() const {
    return data;
}
