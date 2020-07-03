cmake_minimum_required(VERSION 3.14)
project(Argentum_Taller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11  -pedantic -pedantic-errors -O3 -ggdb -DDEBUG -fno-inline")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2_ttf REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2_mixer REQUIRED SDL2_mixer)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(client)
INCLUDE_DIRECTORIES(server)

file(GLOB_RECURSE CLIENT_SOURCES
        src/client/*.h
        src/client/*.cpp)

file(GLOB_RECURSE SERVER_SOURCES
        src/server/*.h
        src/server/*.cpp)

file(GLOB_RECURSE COMMON_SOURCES
        src/common/*.h
        src/common/*.cpp)

add_executable(client ${CLIENT_SOURCES} ${COMMON_SOURCES} src/common/Message.cpp src/common/Message.h src/common/Decoder.cpp src/common/Decoder.h)

add_executable(Server ${SERVER_SOURCES})

target_link_libraries(client
        -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)


