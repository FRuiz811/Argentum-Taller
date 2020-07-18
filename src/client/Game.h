#ifndef GAME_H
#define GAME_H

#include <memory>
#include <unordered_map>
#include "Window.h"
#include "TextureManager.h"
#include "MusicManager.h"
#include "GameMap.h"
#include "Player.h"
#include "NPC.h"
#include "Camera.h"
#include "ui/UI.h"
#include "../common/InputQueue.h"
#include "../common/DataQueue.h"
#include "../common/Socket.h"
#include "../common/Identificators.h"
#include "../common/CommunicationProtocol.h"
#include "Dispatcher.h"
#include "Receiver.h"

//Clase destinada a coordinar el juego del lado del cliente
//Realiza la conexión inicial y luego, irá realizando los updates 
//recibidos desde el server para renderizarlos y enviando
//comandos al mismo. A su vez tendrá otros 2 Threads que 
//establecerán la comunicación con el server

class Game {
private:
    Window window;
    CommunicationProtocol protocol;
    TextureManager textureManager;
    MusicManager musicManager;
    std::unordered_map<uint, NPC> npcs;
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
    void sounds();
    void close();
public:
    Game();
    //Se conecta con el servidor, enviando la raza y clase elegida
    //Recibe el mapa estático y el primer playerInfo que tendrá la
    //información inicial para que el jugador pueda comenzar el juego.
    bool init(char* argv[]);

    //Gameloop principal del cliente.
    int run();

    ~Game();

};

#endif