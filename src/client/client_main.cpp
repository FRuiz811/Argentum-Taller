#include "../common/Socket.h"
#include "../common/CommunicationProtocol.h"
#include "Game.h"
#include <iostream>
#define ARGENTUM "Argentum Online"
#define INVALID_ARGUMENTS "USO: argentum_client <raza> <clase> <host> <puerto>"
#define GAMELOOPTIME 1000000/30.0

int main(int argc, char* argv[]) {
	if (argc != 5) {
		std::cout << INVALID_ARGUMENTS << std::endl;
	return 1;
	}
	
	Game game;
	if (!game.init(argv)) {
		return 1;
	}
	game.run();

	return 0;
}