#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "../common/Thread.h"
#include "../common/InputQueue.h"
#include "../common/CommunicationProtocol.h"

class Dispatcher: public Thread {
private:
    InputQueue& queue;
    std::atomic<bool> keepTalking;
    CommunicationProtocol& protocol;
public:

    Dispatcher(CommunicationProtocol& protocol, InputQueue& queue);

    virtual void run();

    bool is_alive() const;

    void stop();

    virtual ~Dispatcher();

};

#endif
