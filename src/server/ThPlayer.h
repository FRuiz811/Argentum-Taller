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


class ThPlayer : public Thread {
private:
    std::shared_ptr<CommunicationProtocol> protocol;
    std::atomic<bool> keepTalking;
    std::shared_ptr<GameCharacter> character;
    ThPlayerReceiver receiver;
    bool canUpdate = false;
    std::condition_variable cv;
    std::mutex m;
    std::vector<GameObjectInfo> gameObjectsInfo;
    NPCInfo interacting;
public:
    ThPlayer(std::shared_ptr<CommunicationProtocol> protocol, std::shared_ptr<GameCharacter> aCharacter);

    virtual void run();

    void stop();

    bool is_alive() const;

    void update(std::vector<std::shared_ptr<GameObject>> gameObject);

    virtual ~ThPlayer();
};


#endif
