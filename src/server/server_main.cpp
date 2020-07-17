#include <iostream>
#include "World.h"
#include "../common/JsonReader.h"
#include "PlayerAcceptor.h"
#include <string>

#define EXIT "q"    
#define INVALIDARGUMENTS "Error argumentos inválidos: argentum_server <path configuracion>"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << INVALIDARGUMENTS <<std::endl;
        return 1;
    }
    rapidjson::Document jsonConfigStats = JsonReader::read(argv[1]);
    GameStatsConfig gameStatsConfig(jsonConfigStats);
    
    World world(gameStatsConfig);
    PlayerAcceptor acceptor(gameStatsConfig.getPort(),world);

    acceptor.start();
    world.start();
    
    std::string input;
	while (input != EXIT) {
		std::cin >> input;
	}

    world.stop();
	world.join();
    std::cout << "Server Cerrado" << std::endl;
    acceptor.stop();
    acceptor.join();
    return 0;
}

