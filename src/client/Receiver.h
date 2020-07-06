#ifndef RECEIVER_H
#define RECEIVER_H

#include "../common/Thread.h"
#include "../common/DataQueue.h"
#include "../common/CommunicationProtocol.h"

class Receiver: public Thread {
private:
    DataQueue& queue;
    std::atomic<bool> keepTalking;
    CommunicationProtocol& protocol;
public:

    Receiver(CommunicationProtocol& protocol, DataQueue& queue);

    virtual void run();

    bool is_alive() const;

    void stop();

    virtual ~Receiver();

};

#endif
