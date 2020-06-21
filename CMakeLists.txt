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
INCLUDE_DIRECTORIES(Client)
INCLUDE_DIRECTORIES(Server)
add_executable(client
        src/Client/Animation.cpp
        src/Client/Animation.h
        src/Client/client_main.cpp
        src/Client/Exception.cpp
        src/Client/Exception.h
        src/Client/Font.cpp
        src/Client/Font.h
        src/Client/Makefile
        src/Client/Music.cpp
        src/Client/Music.h
        src/Client/MusicID.h
        src/Client/MusicManager.cpp
        src/Client/MusicManager.h
        src/Client/Texture.cpp
        src/Client/Texture.h
        src/Client/TextureID.h
        src/Client/TextureManager.cpp
        src/Client/TextureManager.h
        src/Client/Window.cpp
        src/Client/Window.h
        src/Client/Zombie.cpp
        src/Client/Zombie.h
        src/Client/GameMap.cpp
        src/Client/GameMap.h
        src/Client/Tile.cpp
        src/Client/Tile.h
        src/Client/TiledMap.cpp
        src/Client/TiledMap.h
        src/Client/TileSet.cpp
        src/Client/TileSet.h
        src/Client/Layer.cpp
        src/Client/Layer.h
        src/JsonReader.cpp
        src/JsonReader.h
        src/MapTransformer.cpp
        src/MapTransformer.h
        src/Client/Player.cpp
        src/Client/Player.h
        src/Client/Spider.cpp
        src/Client/Spider.h)

add_executable(Server
        src/Server/Arma.cpp
        src/Server/Arma.h
        src/Server/Ataque.cpp
        src/Server/Ataque.h
        src/Server/Casillero.cpp
        src/Server/Casillero.h
        src/Server/Clase.cpp
        src/Server/Clase.h
        src/Server/Criatura.cpp
        src/Server/Criatura.h
        src/Server/Defensa.cpp
        src/Server/Defensa.h
        src/Server/Ecuacion.cpp
        src/Server/Ecuacion.h
        src/Server/Estado.cpp
        src/Server/Estado.h
        src/Server/Excepciones.cpp
        src/Server/Excepciones.h
        src/Server/Movimiento.cpp
        src/Server/Movimiento.h
        src/Server/NPC.cpp
        src/Server/NPC.h
        src/Server/ObjetoJuego.cpp
        src/Server/ObjetoJuego.h
        src/Server/Personaje.cpp
        src/Server/Personaje.h
        src/Server/Posicion.cpp
        src/Server/Posicion.h
        src/Server/Raza.cpp
        src/Server/Raza.h
        src/Server/StatsJuego.cpp
        src/Server/StatsJuego.h
        src/Server/Tablero.cpp
        src/Server/Tablero.h
        src/Server/testCasillero.cpp
        src/Server/testPersonaje.cpp)

target_link_libraries(client -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)


