#include "GameCharacter.h"

void GameCharacter::update() {

}

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, position.getPoint(), 100, 100, 100, "ht:01|h:01|b:01|s01|w01");
}

GameCharacter::GameCharacter(uint id, int aRace, int aClass, Point &point):  GameObject(id), race(aRace), gameClass(aClass) {
    position = Position(point, 25, 60);
    life = 100;
    goldAmount = 100;
    mana = 100;
}

//void GameCharacter::corroborarAtaque(GameObject &atacado){
//	if(!arma.esArmaDistancia() &&
//		(abs(getCoordenadaX() - atacado.getCoordenadaX()) > 1 ||
//		abs(getCoordenadaY() - atacado.getCoordenadaY()) > 1)) {
//		throw AtaqueInvalido();
//	}
//	if(abs(this->estado.getNivel() - atacado.estado.getNivel()) > 10) { //ToDO: poner en estados
//		throw AtaqueNivelInvalido();
//	}
//}

//void GameCharacter::atacar(GameObject &atacado){
//	corroborarAtaque(atacado);
//	float experiencia = ataque.atacar(atacado, arma, this->estado.getNivel());
//	this->estado.updateNivel(experiencia);
//}
//
//void GameCharacter::equiparArma(Arma arma){
//	this->arma = arma;
//}
	

GameCharacter::~GameCharacter()= default;

