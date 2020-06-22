cmake_minimum_required(VERSION 3.14)
project(Argentum_Taller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic -pedantic-errors -O3 -ggdb -DDEBUG -fno-inline")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2_ttf REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2_mixer REQUIRED SDL2_mixer)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(client)
INCLUDE_DIRECTORIES(server)

add_executable(client
        src/client/Animation.cpp
        src/client/Animation.h
        src/client/client_main.cpp
        src/client/Exception.cpp
        src/client/Exception.h
        src/client/Font.cpp
        src/client/Font.h
        src/client/Makefile
        src/client/Music.cpp
        src/client/Music.h
        src/client/MusicID.h
        src/client/MusicManager.cpp
        src/client/MusicManager.h
        src/client/Texture.cpp
        src/client/Texture.h
        src/client/TextureID.h
        src/client/TextureManager.cpp
        src/client/TextureManager.h
        src/client/Window.cpp
        src/client/Window.h
        src/client/Zombie.cpp
        src/client/Zombie.h
        src/client/GameMap.cpp
        src/client/GameMap.h
        src/client/Tile.cpp
        src/client/Tile.h
        src/client/TiledMap.cpp
        src/client/TiledMap.h
        src/client/TileSet.cpp
        src/client/TileSet.h
        src/client/TileLayer.cpp
        src/client/TileLayer.h
        src/JsonReader.cpp
        src/JsonReader.h
        src/MapTransformer.cpp
        src/MapTransformer.h
        src/client/Player.cpp
        src/client/Player.h
        src/client/Spider.cpp
        src/client/Spider.h
        src/client/ObjectLayer.cpp
        src/client/ObjectLayer.h
        src/client/MapObject.cpp
        src/client/MapObject.h
        src/server/ServerProxy.cpp
        src/server/ServerProxy.h)

add_executable(Server
        src/server/Arma.cpp
        src/server/Arma.h
        src/server/Ataque.cpp
        src/server/Ataque.h
        src/server/Cell.cpp
        src/server/Cell.h
        src/server/Clase.cpp
        src/server/Clase.h
        src/server/Criatura.cpp
        src/server/Criatura.h
        src/server/Defensa.cpp
        src/server/Defensa.h
        src/server/Ecuacion.cpp
        src/server/Ecuacion.h
        src/server/Estado.cpp
        src/server/Estado.h
        src/server/Excepciones.cpp
        src/server/Excepciones.h
        src/server/Movimiento.cpp
        src/server/Movimiento.h
        src/server/NPC.cpp
        src/server/NPC.h
        src/server/GameObject.cpp
        src/server/GameObject.h
        src/server/Character.cpp
        src/server/Character.h
        src/server/Position.cpp
        src/server/Position.h
        src/server/Raza.cpp
        src/server/Raza.h
        src/server/StatsJuego.cpp
        src/server/StatsJuego.h
        src/server/Tablero.cpp
        src/server/Tablero.h
        src/server/testCasillero.cpp
        src/server/testPersonaje.cpp
        src/server/ServerProxy.cpp
        src/server/ServerProxy.h src/server/City.cpp src/server/City.h src/server/Collider.cpp src/server/Collider.h)

target_link_libraries(client -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)


