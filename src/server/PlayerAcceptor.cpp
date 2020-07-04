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
	std::vector<ThPlayer*>::iterator iter;
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
            auto player = new ThPlayer(std::move(socketPlayer),world);
            player->start();
            this->players.push_back(player);
            clear_finished_games();
        } catch (...) {

        }
    }
}

void PlayerAcceptor::stop_players() {
    for (size_t i = 0; i < this->players.size(); i++) {
		this->players[i]->stop();
        this->players[i]->join();
        delete this->players[i];
  }
}

void PlayerAcceptor::stop() {
    this->keepTalking = false;
	this->socket.shutdown(SHUT_RDWR);
	this->socket.close();
	stop_players();
}

PlayerAcceptor::~PlayerAcceptor() {}