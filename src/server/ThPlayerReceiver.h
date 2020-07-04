#ifndef THPLAYERRECEIVER_H
#define THPLAYERRECEIVER_H

#include <atomic>
#include "../common/Thread.h"
#include "../common/CommunicationProtocol.h"
#include "../common/Decoder.h"
#include "../common/InputQueue.h"

class ThPlayerReceiver: public Thread {
private:
    std::atomic<bool> keepTalking;
    CommunicationProtocol& protocol;
    InputQueue& queue;
    uint id{0};
    
public:
    explicit ThPlayerReceiver(CommunicationProtocol& protocol, InputQueue& queue);

    virtual void run();

    void stop();

    void setId(uint id);

    virtual ~ThPlayerReceiver();
};

#endif
