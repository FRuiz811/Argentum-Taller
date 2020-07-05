#include "PlayerAcceptor.h"
#include <sys/socket.h>
#include <iostream>
#define MAX_WAITING 20

PlayerAcceptor::PlayerAcceptor(const std::string& port, World& world) : socket(),
    world(world), players(), keepTalking(true){
        this->socket.bind_and_listen(port.data(), MAX_WAITING);
    std::cout << "Se hizo el bind correctamente " << port.data() << std::endl;
}

void PlayerAcceptor::clear_finished_games() {
	std::vector<ThLobbyPlayer*>::iterator iter;
    iter = this->players.begin();
    while (iter != this->players.end()){
        if ((*iter)->is_alive()){
            (*iter)->join();
            iter = this->players.erase(iter);
        } else {
            iter++;
        }
    }
}

void PlayerAcceptor::run() {
    while (this->keepTalking) {
        try{
            Socket socketPlayer = this->socket.accept();
            auto player = new ThLobbyPlayer(std::move(socketPlayer), world);
            player->start();
            this->players.push_back(player);
            clear_finished_games();
        } catch (...) {

        }
    }
}

void PlayerAcceptor::stop_players() {
    for (auto & player : this->players) {
		player->stop();
        player->join();
        delete player;
  }
}

void PlayerAcceptor::stop() {
    this->keepTalking = false;
	this->socket.shutdown(SHUT_RDWR);
	this->socket.close();
	stop_players();
}

PlayerAcceptor::~PlayerAcceptor() = default;