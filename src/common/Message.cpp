#include "Message.h"

#include <utility>
#include "Exception.h"


Message::~Message() = default;

Message::Message() = default;

uint8_t Message::getType() const {
    return type;
}

uint32_t Message::read(uint8_t bytesToRead) {
    if (pos + bytesToRead >= length) {
        throw Exception("Se quiere ingresar a una posicion no valida");
    }
    return *(data.data() + pos + bytesToRead);
}

Message::Message(std::vector<uint8_t>& data, uint32_t length, uint8_t type) :
data(std::move(data)), length(length), type(type) {}

void Message::clear() {
    pos = 0;
}

uint8_t Message::read8() {
    uint8_t value = read(1);
    pos++;
    return value;
}

uint16_t Message::read16() {
    uint16_t value = read(2);
    pos += 2;
    return value;
}

uint32_t Message::read32() {
    uint32_t value = read(4);
    pos += 4;
    return value;
}

const std::vector<uint8_t> &Message::getData() const {
    return std::move(data);
}
