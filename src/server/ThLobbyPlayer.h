#ifndef ARGENTUM_TALLER_THLOBBYPLAYER_H
#define ARGENTUM_TALLER_THLOBBYPLAYER_H


#include "../common/Thread.h"
#include "World.h"
#include "../common/Socket.h"
#include "../common/CommunicationProtocol.h"

class ThLobbyPlayer : public Thread {
private:
    std::atomic<bool> keepTalking;
    World& world;
    CommunicationProtocol protocol;
public:
    ThLobbyPlayer(Socket socket, World& world);

    void run() override;

    void stop();

    bool is_alive() const;

    ~ThLobbyPlayer() override;
};


#endif //ARGENTUM_TALLER_THLOBBYPLAYER_H
