#include "Game.h"
#include <memory>
#include <stdexcept>
#include "Presentation.h"
#include "../common/Chrono.h"
#include "../common/TiledMap.h"
#include <arpa/inet.h>
#include <iostream>
#include "../common/Decoder.h"
#include "../common/SocketException.h"

#define WRONGRACE "Raza invalida. Seleccione entre: elfo, gnomo, humano, enano."
#define WRONGCLASS "Clase invalida. Seleccione entre: mago, clerigo, paladin, guerrero"
#define ARGENTUM "Argentum Online Taller"
#define INITERROR "Error en Game::init: "
#define GAMELOOPTIME 1000000/30.0
#define PLAYERINFOMSG 0x01
#define OBJECTSINFOMSG 0x02
#define INTERACTMSG 0x05

Game::Game() : window(ARGENTUM), protocol(), textureManager(window.getRenderer()),
    musicManager(), npcs(), commandQueue(true), dataQueue(false),
    dispatcher(protocol,commandQueue), receiver(protocol,dataQueue) {}

void Game::recieveMapAndPlayer() {

    Message msgMap = this->protocol.receive();
    TiledMap tiledMap = Decoder::decodeMap(msgMap);
 
    Message msgPlayerInfo = this->protocol.receive();
    PlayerInfo info = Decoder::decodePlayerInfo(msgPlayerInfo);

    this->map = std::make_shared<GameMap>(tiledMap,this->window.getRenderer());
    this->player = std::make_shared<Player>(this->textureManager, info);
}

bool Game::init(char* argv[]) {
    try{
        this->protocol.connect(argv[3], argv[4]);
        std::cout << "me conecte a " << argv[4] << std::endl;
        std::vector<uint8_t> initMsg;
        initMsg = Decoder::encodeInit(translateRace(argv[1]),translateGameClass(argv[2]));
        this->protocol.send(initMsg);
        this->textureManager.loadTextures();
        this->musicManager.loadSounds();
        recieveMapAndPlayer();

        this->camera = std::shared_ptr<Camera>(new Camera(this->window, this->map->getMapWidth(), this->map->getMapHeight()));
        this->ui = std::shared_ptr<UI>(new UI(this->window, &(*this->player), this->textureManager));

    } catch (const SocketException& e) {
        std::cout << INITERROR << e.what() << std::endl;
        return false;
    }
    return true;
}

int Game::run() {
    const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

    Presentation presentation(window, textureManager);
	if (presentation.run())
		return 0;

    this->dispatcher.start();
    this->receiver.start();
    bool quit = false;
    SDL_Event event;

    Chrono chrono;
	double initLoop, endLoop, sleep;
	InputInfo input;
    while (!quit) {
        try{
		    initLoop = chrono.lap();
		    while (SDL_PollEvent(&event) != 0) {
			    if (event.type == SDL_QUIT) {
			    	quit = true;
                    break;
			    }
			    if(event.type == SDL_KEYDOWN) {
				    if (event.key.keysym.sym == SDLK_m) {
					    musica.pauseMusic();
				    }
			    }
                input = player->handleEvent(event,*camera);
                this->commandQueue.push(input);
			    input = ui->handleClick(event);
			    this->commandQueue.push(input);
			    window.handleEvent(event);
		    }
        
            this->update();
            this->render();

		    endLoop = chrono.lap();
		    sleep = GAMELOOPTIME - (endLoop - initLoop);
		    if (sleep > 0)
			    usleep(sleep);
	    } catch (const std::exception& e) {
            quit = true;
        } catch (...) {
            quit = true;
            std::cerr << "Unkown Error in Game::run()" << std::endl;
     }
    }

    close();


    return 0;

}

void Game::update() {
    Message msg;
    PlayerInfo playerInfo;
    std::vector<GameObjectInfo> objects;
    std::unordered_map<uint,NPC> newNpcs;
    //NPCMessage items;
    while (!this->dataQueue.empty()){
        msg = this->dataQueue.pop();
        if (msg.getType() == PLAYERINFOMSG) {
            playerInfo = Decoder::decodePlayerInfo(msg);
            this->player->updatePlayerInfo(playerInfo);
        } else if (msg.getType() == OBJECTSINFOMSG) {
            objects = Decoder::decodeGameObjects(msg);
            newNpcs.clear();
            for (GameObjectInfo& npc : objects) {
                auto iter = this->npcs.find(npc.getId());
                if (iter == this->npcs.end()){
                    NPC aNpc(this->textureManager,npc);
                    newNpcs.insert({npc.getId(),aNpc});
                } else {
                    (*iter).second.updatePlayerInfo(npc);
                    newNpcs.insert({(*iter).first,(*iter).second});
                }
		    }
            this->npcs.swap(newNpcs);
        } else if (msg.getType() == INTERACTMSG) {
            //items = Decoder::decodeInteractNPC(msg);
            //this->ui->setNPCInfo(items);
        }
    }
    this->player->update(GAMELOOPTIME);
    for (auto& npc: this->npcs)
        npc.second.update(GAMELOOPTIME);
    //this->ui->update();
}

void Game::render() {
		window.clearScreen();

		ui->render();
        Point* center = this->player->getCenter();
        camera->setPlayer(center);
	    camera->render(*center);
        this->map->drawGround(*camera);
		this->player->render(*camera);

		for (auto& aNPC : this->npcs) {
		    aNPC.second.render(*camera);
		}

		this->map->drawHighLayers(*camera);

		this->window.render();
}

void Game::close() {
    std::cout << "Cierro todo" << std::endl;
    this->dataQueue.close();
    this->commandQueue.close();
    this->receiver.stop();
    this->receiver.join();
    this->dispatcher.stop();
    this->dispatcher.join();
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

Game::~Game() {}