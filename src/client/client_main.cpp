#include "SDL2/SDL.h"
#include <unistd.h>
#include <iostream>
#include "Window.h"
#include "Chrono.h"
#include "Music.h"
#include "MusicManager.h"
#include "TextureManager.h"
#include "MusicID.h"
#include "Presentation.h"
#include "GameMap.h"
#include "Player.h"
#include "Camera.h"
#include "UI.h"
#include "NPC.h"
#include "../common/Socket.h"
#include "../common/CommunicationProtocol.h"
#include "Game.h"

#define ARGENTUM "Argentum Online"
#define INVALID_ARGUMENTS "USO: ./client <raza> <clase> <host> <puerto>"
#define GAMELOOPTIME 1000000/30.0

int main(int argc, char* argv[]) {
	//if (argc != 5) {
	//	std::cout << INVALID_ARGUMENTS << std::endl;
	//	return 1;
	//}

	if(argc == 5) {
		Game game;

		if (game.init(argv)) {
			return 1;
		}
		
		game.run();
		
		return 0;
	}

	ServerProxy serverProxy;
	PlayerInfo playerInfo = serverProxy.createCharacter(RaceID::Elf, GameClassID::Paladin);
	bool quit = false;
	SDL_Event event;
	Window window(ARGENTUM);

	TextureManager textureManager(window.getRenderer());
	textureManager.loadTextures();

	MusicManager musicManager;
	musicManager.loadSounds();
	const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

	GameMap gameMap(serverProxy.getStaticMap(), window.getRenderer());

	Presentation presentation(window, textureManager);
	if (presentation.run())
		return 0;

	Player player(textureManager, playerInfo);
	std::vector<NPC> npcs;

	Chrono chrono;
	double initLoop, endLoop, sleep;
	Camera camera(window, gameMap.getMapWidth(), gameMap.getMapHeight());
	UI ui(window, &player, textureManager);
	InputInfo input;

	while (!quit) {
		initLoop = chrono.lap();
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_m) {
					musica.pauseMusic();
				}
                input = player.handleEvent(event,camera);
                serverProxy.sendInput(input, playerInfo.getId());
			}
			if (event.type == SDL_KEYUP) {
                input = player.handleEvent(event,camera);
                serverProxy.sendInput(input, playerInfo.getId());
			}
			input = ui.handleClick(event);
			serverProxy.sendInput(input, player.getId());
			window.handleEvent(event);
		}
        serverProxy.update();
		playerInfo = serverProxy.getUpdatedPlayerInfo(playerInfo.getId());
		player.updatePlayerInfo(playerInfo);
		npcs.clear();
		for (GameObjectInfo& aGameObjectInfo : serverProxy.getUpdatedGameObjects()) {
	   		if (aGameObjectInfo.getId() == playerInfo.getId()) {
          	 	continue;
	    	}
	    	npcs.emplace_back(textureManager, aGameObjectInfo);
		}
		player.update(GAMELOOPTIME);
        for (auto& npc: npcs)
            npc.update(GAMELOOPTIME);
		window.clearScreen();
		Point* center = player.getCenter();
		window.clearScreen();
		ui.render();
		camera.setPlayer(center);
		camera.update(*center);
        gameMap.drawGround(camera);
		player.render(camera);
		for (auto& aNPC : npcs) {
		    aNPC.render(camera);
		}
		gameMap.drawHighLayers(camera);
		window.render();

		endLoop = chrono.lap();
		sleep = GAMELOOPTIME - (endLoop - initLoop);
		if (sleep > 0)
			usleep(sleep);
	}
	return 0;
}