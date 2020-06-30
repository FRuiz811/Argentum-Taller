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
#include "NPC.h"


#define ARGENTUM "Argentum Online"
#define GAMELOOPTIME 1000/30.0

int main(int argc, char* args[]) {
	//Debería ser 5 argc
	//Realizar el connect al host & port indicado.
	ServerProxy serverProxy;
	PlayerInfo playerInfo = serverProxy.createCharacter(RaceID::Human, GameClassID::Paladin);
	bool quit = false;
	SDL_Event event;

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
		camera.setPlayer(center);
		camera.moveTo(*center);
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