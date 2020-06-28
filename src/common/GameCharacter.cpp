#include "GameCharacter.h"
#include "../client/Exception.h"
#include "Collider.h"

void GameCharacter::update() {

}

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, position.getPoint(), goldAmount, life, mana, textureHashId, direction);
}

GameCharacter::GameCharacter(uint id, int aRace, int aClass, Point &point):  GameObject(id), race(aRace), gameClass(aClass) {
    position = Position(point, 25, 60);
    life = 100;
    goldAmount = 100;
    mana = 50;
    direction = Direction::down;
    textureHashId = "ht03|h02|b05|s00|w06";
}

void GameCharacter::move(Direction aDirection, const std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                         const std::vector<StaticObject> &collisionObjects) {
    bool canMove = true;
    Point newPoint = position.getPoint();
    switch(aDirection) {
        case Direction::up:
            newPoint.y -= 15;
            break;
        case Direction::down:
            newPoint.y += 15;
            break;
        case Direction::left:
            newPoint.x -= 15;
            break;
        case Direction::right:
            newPoint.x += 15;
            break;
        default:
            throw Exception("Invalid Direction");
    }
    direction = aDirection;
    Position newPosition(newPoint, position.getWidth(), position.getHeight());
    for (auto& collisionObject : collisionObjects) {
        if (Collider::checkCollision(newPosition, collisionObject.getPosition())) {
            canMove = false;
            break;
        }
    }
    for (auto& gameObject : gameObjects) {
        if (gameObject.first == id) {
            continue;
        }
        if (Collider::checkCollision(newPosition, gameObject.second->getPosition())) {
            canMove = false;
            break;
        }
    }
    if (canMove) {
        this->setPosition(newPosition);
    }
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

