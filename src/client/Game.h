#ifndef GAME_H
#define GAME_H

#include <memory>
#include "Window.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "GameMap.h"
#include "Player.h"
#include "NPC.h"
#include "Camera.h"
#include "UI.h"
#include "../common/InputQueue.h"
#include "../common/DataQueue.h"
#include "../common/Socket.h"
#include "../common/Identificators.h"
#include "../common/CommunicationProtocol.h"
#include "Dispatcher.h"
#include "Receiver.h"

class Game {
private:
    Window window;
    CommunicationProtocol protocol;
    TextureManager textureManager;
    MusicManager musicManager;
    std::vector<NPC> npcs;
    std::shared_ptr<Player> player = nullptr;
    std::shared_ptr<GameMap> map = nullptr;
    InputQueue commandQueue;
    DataQueue dataQueue;
    Dispatcher dispatcher;
    Receiver receiver;
    std::shared_ptr<Camera> camera{nullptr};
    std::shared_ptr<UI> ui{nullptr};

    RaceID translateRace(const std::string& race);
    GameClassID translateGameClass(const std::string& gameClass);
    void recieveMapAndPlayer();

    void update();
    void render();
    void close();
public:
    Game();

    bool init(char* argv[]);

    int run();

    ~Game();

};

#endif