#include "GameCharacter.h"
#include "Collider.h"
#include "ServerStillState.h"
#include "GameStatsConfig.h"

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, position.getPoint(), goldAmount, life, mana, textureHashId, direction,150,
        100,100,125,1500,2,inventory,state->getStateId());
}

GameCharacter::GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point &point):
GameObject(id), race(aRace), gameClass(aClass), queueInputs(true) {
    this->position = Position(point, 25, 60);
    this->life = 100;
    this->goldAmount = 100;
    this->mana = 100;
    this->exp = 0;
    this->level = 1;
    this->direction = Direction::down;
    this->textureHashId = updateTextureHashId(); //Solo debería tener la cabeza correspondiente y su cuerpo. "ht00|h03|b01|s00|w00"
    this->inventory = "00|00|00|00|00|00|00|00|00"; //Esto debería ser todo 0 al principio del juego
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
    this->textureHashId = updateTextureHashId();
}

std::string GameCharacter::updateTextureHashId() {
    std::string equipment;
    std::string idHelmet = std::to_string((int)this->helmet);
    equipment += "ht";
    if (idHelmet.size() == 1)
        equipment += "0"; 
    equipment += idHelmet + "|"; 
    equipment += "h";
    std::string idHead = std::to_string((int)this->race);
     if (idHead.size() == 1)
        equipment += "0";
    equipment += idHead + "|";
    equipment += "b";
    if (this->body == BodyID::Nothing) {
        this->body = (BodyID)((rand() % 3) + 1);
    }
    std::string idBody = std::to_string((int)this->body);
    if (idBody.size() == 1)
        equipment += "0";
    equipment += idBody + "|";
    std::string idShield = std::to_string((int)this->shield);
    equipment += "s";
    if (idShield.size() == 1)
        equipment += "0";
    equipment += idShield + "|";
    equipment += "w";
    std::string idWeapon = std::to_string((int)this->weapon); 
    if (idWeapon.size() == 1)
        equipment += "0";
    equipment += idWeapon;
    return std::move(equipment);
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

InputQueue &GameCharacter::getQueueInputs() {
    return queueInputs;
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

