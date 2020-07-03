#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Window.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "GameMap.h"
#include "Player.h"
#include "NPC.h"
#include "../common/InputQueue.h"
#include "../common/DataQueue.h"
#include "../common/Socket.h"
#include "../common/Identificators.h"
#include "../common/CommunicationProtocol.h"
#include "Dispatcher.h"
#include "Receiver.h"

class Game {
private:
    CommunicationProtocol protocol;
    Socket socket;
    Window window;
    TextureManager textureManager;
    MusicManager musicManager;
    std::vector<NPC> npcs;
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<GameMap> map = nullptr;
    InputQueue commandQueue;
    DataQueue dataQueue;
    //Dispatcher dispatcher;
    //Receiver receiver;

    RaceID translateRace(const std::string& race);
    GameClassID translateGameClass(const std::string& gameClass);
    void recieveMapAndPlayer();

public:
    Game();

    bool init(char* argv[]);

    int run();

    void update();

    void render(UI* ui, Camera* camera);

    ~Game();

};

#endif