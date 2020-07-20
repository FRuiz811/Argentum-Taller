#include "Dispatcher.h"
#include <vector>
#include <iostream>
#include "../common/SocketException.h"
#include "../common/Decoder.h"

#define UNKNOW_ERROR "Unknow Error"
#define ERRORSOCKET "Error en la comunicación en Dispatcher::run() "
#define ERRORDISPATCHER "Error en Dispatcher::run() "

Dispatcher::Dispatcher(CommunicationProtocol& protocol, InputQueue& queue) :
    queue(queue), keepTalking(true), protocol(protocol) {}

void Dispatcher::run() {
    InputInfo info;
    std::vector<uint8_t> msg;
    while (this->keepTalking) {
        try{
            info = this->queue.pop();
            if (info.input != InputID::nothing) {
                msg = Decoder::encodeCommand(info);
                this->protocol.send(msg);
            }
        } catch (const SocketException& e) {
            std::cerr << ERRORSOCKET << e.what() << std::endl;
            this->keepTalking = false;
        } catch(const std::exception& e){
            std::cerr << ERRORDISPATCHER << e.what() << std::endl;
            this->keepTalking = false;
        }catch (...) {
            this->keepTalking = false;
            std::cerr << UNKNOW_ERROR << std::endl;
        }

    }
}

bool Dispatcher::is_alive() const {
    return this->keepTalking;
}

void Dispatcher::stop() {
    this->keepTalking = false;
    this->protocol.stop();
}

Dispatcher::~Dispatcher() {}