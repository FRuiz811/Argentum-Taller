#include "Receiver.h"
#include <vector>
#include <iostream>
#include "../common/Message.h"
#include "../common/SocketException.h"

#define UNKNOW_ERROR "Unknow Error"
#define ERRORSOCKET "Error en la comunicación en Receiver::run() "
#define ERRORRECEIVER "Error en Receiver::run() "

Receiver::Receiver(CommunicationProtocol& protocol, DataQueue& queue) :
    queue(queue), keepTalking(true), protocol(protocol) {}

void Receiver::run() {
    Message msg;
    while (this->keepTalking){
        try {
            msg = this->protocol.receive();
            this->queue.push(msg);
        }  catch (const SocketException& e) {
            std::cerr << ERRORSOCKET << e.what() << std::endl;
            this->keepTalking = false;
        } catch(const std::exception& e){
            std::cerr << ERRORRECEIVER << e.what() << std::endl;
            this->keepTalking = false;
        }catch (...) {
            this->keepTalking = false;
            std::cerr << UNKNOW_ERROR << std::endl;
        }
    }
}

bool Receiver::is_alive() const {
    return this->keepTalking;
}

void Receiver::stop() {
    this->keepTalking = false;
    this->protocol.stop();
}

Receiver::~Receiver() {}