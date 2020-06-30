#include "SDL2/SDL.h"
#include <unistd.h>
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
#include "../common/Point.h"
#include "NPC.h"
#include "../common/Socket.h"
#include "../common/CommunicationProtocol.h"

#define ARGENTUM "Argentum Online"
#define INVALID_ARGUMENTS "Error: argumentos invalidos."
#define GAMELOOPTIME 1000/30.0

int main(int argc, char* argv[]) {
	//Debería ser 5 argc
	//Realizar el connect al host & port indicado.

	ServerProxy serverProxy;
	PlayerInfo playerInfo = serverProxy.createCharacter(RaceID::Human, GameClassID::Paladin);
	bool quit = false;
	SDL_Event event;
	if(argc == 3) {
		Socket socket;
		socket.connect(argv[1], argv[2]);
		CommunicationProtocol protocol;
		std::vector<uint8_t> encoding = protocol.encodePlayerInfo(playerInfo);
		socket.send(encoding.data(),encoding.size());
		PlayerInfo info = protocol.decodePlayerInfo(encoding);
		return 0;
	}
	Window window(ARGENTUM);
    GameMap gameMap(serverProxy.getStaticMap(), window.getRenderer());

	TextureManager textureManager(window.getRenderer());
	textureManager.loadTextures();

	MusicManager musicManager;
	musicManager.createMusic(MusicID::Start, "assets/sound/Musica Inicio.mp3");
	const Music& musica = musicManager.getMusic(MusicID::Start);
	musica.playMusic(-1);

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
			} else if(event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_m) {
					musica.pauseMusic();
				}
				input = player.handleEvent(event);
				serverProxy.sendInput(input, playerInfo.getId());
			}
			ui.handleClick(event);
			window.handleEvent(event);
		}
        serverProxy.update();
		playerInfo = serverProxy.getUpdatedPlayerInfo(playerInfo.getId());
		player.updatePlayerInfo(playerInfo);
		for (GameObjectInfo& aGameObjectInfo : serverProxy.getUpdatedGameObjects()) {
	   		if (aGameObjectInfo.getId() == playerInfo.getId()) {
          	 	continue;
	        }
	    	npcs.emplace_back(textureManager, aGameObjectInfo);
		}
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