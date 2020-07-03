#ifndef ARGENTUM_TALLER_MESSAGE_H
#define ARGENTUM_TALLER_MESSAGE_H


#include <vector>
#include <cstdint>

class Message {
private:
    std::vector<uint8_t> data;
    uint32_t length{};
    uint8_t type{};
    uint32_t pos = 0;

    uint32_t read(uint8_t bytesToRead);

public:
    Message();

    Message(std::vector<uint8_t> data, uint32_t length, uint8_t type);

    ~Message();

    uint8_t getType() const;

    const std::vector<uint8_t> &getData() const;

    void clear();

    uint8_t read8();

    uint16_t read16();

    uint32_t read32();
};


#endif //ARGENTUM_TALLER_MESSAGE_H
