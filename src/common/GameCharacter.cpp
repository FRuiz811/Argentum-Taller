#include "GameCharacter.h"
#include "Collider.h"
#include "ServerStillState.h"
#include "GameStatsConfig.h"

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, position.getPoint(), goldAmount, life, mana, textureHashId, direction);
}

GameCharacter::GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point &point):
GameObject(id), race(aRace), gameClass(aClass), queueInputs() {
    this->position = Position(point, 25, 60);
    this->life = 100;
    this->goldAmount = 100;
    this->mana = 100;
    this->exp = 0;
    this->direction = Direction::down;
    this->textureHashId = "ht01|h01|b01|s01|w01";
    InputInfo anInputInfo;
    anInputInfo.input = InputID::nothing;
    anInputInfo.position = Point(0.0, 0.0);
    this->state = std::unique_ptr<State>(new ServerStillState(anInputInfo));

}

void GameCharacter::receiveInput(InputInfo anInputInfo) {
    queueInputs.push(anInputInfo);
}

void GameCharacter::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                           GameStatsConfig &gameStatsConfig) {
    if (state->isOver()) {
        if (!state->hasNextState() && !queueInputs.empty()) {
            state->setNextState(queueInputs.pop());
            state = state->getNextState();
        } else {
            state->resetState();
        }
    }
    state->performTask(id, gameObjects, board, gameStatsConfig);
}

RaceID GameCharacter::getRace() const {
    return race;
}

GameClassID GameCharacter::getGameClass() const {
    return gameClass;
}

uint GameCharacter::getGoldAmount() const {
    return goldAmount;
}

uint GameCharacter::getLife() const {
    return life;
}

uint GameCharacter::getMana() const {
    return mana;
}

float GameCharacter::getExp() const {
    return exp;
}

uint GameCharacter::getLevel() const {
    return level;
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

