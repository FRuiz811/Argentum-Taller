#include "GameCharacter.h"
#include "Collider.h"
#include "ServerStillState.h"
#include "GameStatsConfig.h"

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, boardPosition.getPosition().getPoint(), goldAmount, life, mana, textureHashId, direction,150,
        100,100,125,1500,2,"02|20|12|10|03|00|00|00|00",state->getStateId());
}

GameCharacter::GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point &point):
GameObject(id), race(aRace), gameClass(aClass), queueInputs() {
    boardPosition = BoardPosition(Position(point, 25, 60), 0, true);
    this->life = 100;
    this->goldAmount = 100;
    this->mana = 50;
    this->exp = 0;
    this->textureHashId = "ht03|h02|b05|s00|w06";
    InputInfo anInputInfo;
    anInputInfo.input = InputID::nothing;
    state = std::unique_ptr<State>(new ServerStillState(anInputInfo));
}

void GameCharacter::receiveInput(InputInfo anInputInfo) {
    queueInputs.push(anInputInfo);
}

void GameCharacter::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                           GameStatsConfig &gameStatsConfig) {
    if (state->isOver()) {
        if (!queueInputs.empty()) {
            state->setNextState(queueInputs.pop());
        } else {
            state->resetState();
        }
        if (state->hasNextState()) {
            state = state->getNextState();
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

CharacterStateID GameCharacter::getStateId() {
    return state->getStateId();
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

