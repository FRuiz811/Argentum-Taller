#ifndef SERVERPLAYER_H
#define SERVERPLAYER_H

#include <atomic>
#include "../common/Thread.h"
#include "../common/CommunicationProtocol.h"
#include "../common/Socket.h"
#include "World.h"
#include "ThPlayerReceiver.h"
#include "../common/PlayerInfo.h"

class ThPlayer : public Thread {
private:
    CommunicationProtocol protocol;
    World& world;
    std::atomic<bool> keepTalking;
    ThPlayerReceiver receiver;
    PlayerInfo player;
public:
    ThPlayer(Socket socket, World& world);

    virtual void run();

    void stop();

    bool is_alive() const;

    virtual ~ThPlayer();
};


#endif
