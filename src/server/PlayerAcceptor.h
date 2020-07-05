#ifndef PLAYERACCEPTOR_H
#define PLAYERACCEPTOR_H

#include "../common/Thread.h"
#include "../common/Socket.h"
#include "ThPlayer.h"
#include "World.h"
#include "ThLobbyPlayer.h"

class PlayerAcceptor: public Thread {
private:
    Socket socket;
    World& world;
    std::vector<ThLobbyPlayer*> players;
    std::atomic<bool> keepTalking;

    void clear_finished_games();
    void stop_players(); 
public:
    explicit PlayerAcceptor(const std::string& port, World& world);

    virtual void run();

    void stop();

    virtual ~PlayerAcceptor();
};

#endif