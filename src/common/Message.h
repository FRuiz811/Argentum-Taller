#ifndef ARGENTUM_TALLER_MESSAGE_H
#define ARGENTUM_TALLER_MESSAGE_H


#include <vector>
#include <cstdint>

//Wrapper del mensaje recibido por el socket.
//Se puede obtener la longitud del mismo, su tipo de mensaje
//y la información propiamente del mensaje enviado.
//Además provee un mecanismo de lectura de distintos bytes.
class Message {
private:
    std::vector<uint8_t> data;
    uint32_t length{};
    uint8_t type{};
    uint32_t pos = 0;
public:
    Message();

    Message(std::vector<uint8_t>& data, uint32_t length, uint8_t type);

    ~Message();

    uint8_t getType() const;

    void clear();

    uint8_t read8();

    uint16_t read16();

    uint32_t read32();
};

#endif //ARGENTUM_TALLER_MESSAGE_H
