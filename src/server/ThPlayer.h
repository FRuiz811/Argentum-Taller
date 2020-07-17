#ifndef SERVERPLAYER_H
#define SERVERPLAYER_H

#include <atomic>
#include <mutex>
#include <condition_variable>
#include "../common/Thread.h"
#include "../common/CommunicationProtocol.h"
#include "../common/Socket.h"
#include "ThPlayerReceiver.h"
#include "../common/PlayerInfo.h"
#include "GameCharacter.h"
#include "WorldInfoQueue.h"


class ThPlayer : public Thread {
private:
    std::shared_ptr<CommunicationProtocol> protocol;
    std::atomic<bool> keepTalking;
    std::shared_ptr<GameCharacter> character;
    ThPlayerReceiver receiver;
    WorldInfoQueue worldInfoQueue;

public:
    ThPlayer(const std::shared_ptr<CommunicationProtocol>& protocol, std::shared_ptr<GameCharacter> aCharacter);

    virtual void run();

    void stop();

    bool is_alive() const;

    void update(const WorldInfo& worldInfo);

    virtual ~ThPlayer();
};


#endif
