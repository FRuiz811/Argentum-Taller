#include "Game.h"
#include <stdexcept>
#include "Presentation.h"
#include "Chrono.h"
#include "../common/TiledMap.h"
#include <arpa/inet.h>

#define WRONGRACE "Raza invalida. Seleccione entre: elfo, gnomo, humano, enano."
#define WRONGCLASS "Clase invalida. Seleccione entre: mago, clerigo, paladin, guerrero"
#define ARGENTUM "Argentum Online Taller"
#define GAMELOOPTIME 1000000/30.0
#define PLAYERINFOMSG 0x01
#define OBJECTSINFOMSG 0x02

Game::Game() : protocol(), socket(), window(ARGENTUM), textureManager(window.getRenderer()),
    musicManager(), npcs(), commandQueue(true), dataQueue(false) {}

void Game::recieveMapAndPlayer() {
    uint8_t length[5];
    this->socket.recieve(&length, 5);
    uint32_t* temp32 = (uint32_t*) length;
	uint32_t length_message = ntohl(*temp32);
    uint8_t type = length[4];

    std::vector<uint8_t> buffer(length_message,0);
    uint8_t* buf = buffer.data();
    this->socket.recieve(buf, length_message);
    //TileMap& tileMap = this->protocol.decodeMap(buffer);
 
    this->socket.recieve(&length, 5);
    temp32 = (uint32_t*) length;
	length_message = ntohl(*temp32);
    type = length[4];

    buffer.resize(length_message,0);
    buf = buffer.data();
    this->socket.recieve(buf, length_message);
    PlayerInfo info = this->protocol.decodePlayerInfo(buffer);
    
    //this->map = std::shared_ptr<GameMap>(new GameMap(tileMap,this->window.getRenderer()));
    this->player = std::shared_ptr<Player>(new Player(this->textureManager, info));
}

bool Game::init(char* argv[]) {
    try{
        this->socket.connect(argv[3], argv[4]);
        std::vector<uint8_t> initMsg;
        initMsg = protocol.encodeInit(translateRace(argv[1]),translateGameClass(argv[2]));
        this->socket.send(initMsg.data(),initMsg.size());

        recieveMapAndPlayer();

        //Lanzar a correr ambos hilos
        this->textureManager.loadTextures();
        this->musicManager.loadSounds();

       //this->dispatcher.run();
       //this->receiver.run();
    } catch (...) {

    }
}

int Game::run() {
    const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

    Presentation presentation(window, textureManager);
	if (presentation.run())
		return 0;

    bool quit = false;
    SDL_Event event;

    Chrono chrono;
	double initLoop, endLoop, sleep;
	Camera camera(window, this->map->getMapWidth(), this->map->getMapHeight());
	UI ui(window, &(*player), textureManager);
	InputInfo input;

	while (!quit) {
		initLoop = chrono.lap();
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_m) {
					musica.pauseMusic();
				}
				input = player->handleEvent(event,camera);
                this->commandQueue.push(input);
			}
			input = ui.handleClick(event);
			this->commandQueue.push(input);
			window.handleEvent(event);
		}
        
        this->update();
        this->render(&ui, &camera);

		endLoop = chrono.lap();
		sleep = GAMELOOPTIME - (endLoop - initLoop);
		if (sleep > 0)
			usleep(sleep);
	}
    return 0;

}

void Game::update() {
    Message msg;
    PlayerInfo playerInfo;
    std::vector<GameObjectInfo> objects;

    while (!this->dataQueue.empty()){
        msg = this->dataQueue.pop();
        /* if (msg.getType() == PLAYERINFOMSG) {
            Traducir el player info
            this->player->updatePlayerInfo(playerInfo);
        } else if (msg.getType() == OBJECTSINFOMSG) {
            Traducir el GameObjectInfo
            for (GameObjectInfo& npc : objects) {
	   		if (npc.getId() == this->player->getId()) {
          	 	continue;
	    	}
	    	this->npcs.emplace_back(this->textureManager, npc);
		} 
        }*/
    }
}

void Game::render(UI* ui, Camera* camera) {
        Point* center = this->player->getCenter();
		window.clearScreen();

		ui->render();
		camera->setPlayer(center);
		camera->update(*center);
        this->map->drawGround(*camera);
		this->player->render(*camera);

		for (auto& aNPC : this->npcs) {
		    aNPC.render(*camera);
		}

		this->map->drawHighLayers(*camera);

		this->window.render();
}

RaceID Game::translateRace(const std::string& race){
    RaceID selectedRace;
    if (race == "elfo") {
        selectedRace = RaceID::Elf;
    } else if (race == "enano") {
        selectedRace = RaceID::Dwarf;
    } else if (race == "humano") {
        selectedRace = RaceID::Human;
    } else if (race == "gnomo") {
        selectedRace = RaceID::Gnome;
    } else {
        throw std::invalid_argument(WRONGRACE);
    }
    return selectedRace;
}

GameClassID Game::translateGameClass(const std::string& gameClass){
    GameClassID selectedClass;
    if (gameClass == "mago") {
        selectedClass = GameClassID::Mage;
    } else if (gameClass == "clerigo") {
        selectedClass = GameClassID::Cleric;
    } else if (gameClass == "guerrero") {
        selectedClass = GameClassID::Warrior;
    } else if (gameClass == "paladin") {
        selectedClass = GameClassID::Paladin;
    } else {
        throw std::invalid_argument(WRONGCLASS);
    }
    return selectedClass;
}

Game::~Game() {
    //this->dispatcher.stop();
    //this->receiver.stop();
   // this->dispatcher.join();
   //this->receiver.join();
}