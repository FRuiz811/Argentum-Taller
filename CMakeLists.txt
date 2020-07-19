cmake_minimum_required(VERSION 3.14)
project(Argentum_Taller)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror -pedantic -pedantic-errors -O3 -ggdb -DDEBUG -fno-inline -pthread")

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2_image REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2_ttf REQUIRED SDL2_ttf)
PKG_SEARCH_MODULE(SDL2_mixer REQUIRED SDL2_mixer)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR} ${SDL2MIXER_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(src/client)
INCLUDE_DIRECTORIES(src/server)

file(GLOB_RECURSE CLIENT_SOURCES
        src/client/*.h
        src/client/*.cpp)

file(GLOB_RECURSE SERVER_SOURCES
        src/server/*.h
        src/server/*.cpp)

file(GLOB_RECURSE COMMON_SOURCES
        src/common/*.h
        src/common/*.cpp)

add_executable(argentum_client ${CLIENT_SOURCES} ${COMMON_SOURCES})
add_executable(argentum_server ${SERVER_SOURCES} ${COMMON_SOURCES})

target_link_libraries(argentum_client -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer pthread)
target_link_libraries(argentum_server pthread)

set(DEV yes)
#ifdef DEV
#define ROOT_DIR "./"
#define CONFIG_DIR "./"
#else
#define ROOT_DIR "/var/Argentum"
#define CONFIG_DIR "/etc/Argentum"
#endif

file(COPY assets DESTINATION ./)
file(COPY json/gameStats.json json/bigMapNPC.json json/finishedMap.json DESTINATION ./)
file(COPY include DESTINATION ./)

INSTALL(TARGETS argentum_client argentum_server DESTINATION /usr/bin)
INSTALL(DIRECTORY assets DESTINATION /var/Argentum)
INSTALL(DIRECTORY include DESTINATION /var/Argentum)
INSTALL(FILES gameStats.json bigMapNPC.json finishedMap.json DESTINATION /etc/Argentum)
