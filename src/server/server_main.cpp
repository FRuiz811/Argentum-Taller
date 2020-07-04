#include <iostream>
#include "World.h"
#include "../common/JsonReader.h"
#include "../common/ConfigFileTransformer.h"
#include "PlayerAcceptor.h"
#include <iostream>
#include <string>

#define EXIT "q"    
#define INVALIDARGUMENTS "Error argumentos inválidos: ./server <path configuracion>"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << INVALIDARGUMENTS <<std::endl;
        return 1;
    }
    rapidjson::Document jsonConfigStats = JsonReader::read(argv[1]);
    GameStatsConfig gameStatsConfig = ConfigFileTransformer::transform(jsonConfigStats);
    
    World world(gameStatsConfig);
    PlayerAcceptor acceptor(gameStatsConfig.getPort(),world);

    acceptor.start();
    world.start();
    
    std::string input;
	while (input != EXIT) {
		std::cin >> input;
	}

    
    world.join();
    acceptor.stop();
    acceptor.join();
    return 0;
}

