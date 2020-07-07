#include <iostream>
#include "GameCharacter.h"
#include "states/StillStateCharacter.h"
#include "GameStatsConfig.h"
#include "states/DeadStateCharacter.h"

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, boardPosition.getPosition().getPoint(), goldAmount, life, mana, textureHashId, direction,150,
        100,100,exp,1500,2,inventory,state->getStateId());
}

GameCharacter::GameCharacter(uint id, RaceID aRace, GameClassID aClass, Point &point):
GameObject(id), race(aRace), gameClass(aClass), queueInputs(true) {
    boardPosition = BoardPosition(Position(point, 25, 60), 0, true);
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
    state = std::unique_ptr<State>(new StillStateCharacter(anInputInfo));
}

void GameCharacter::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                           GameStatsConfig &gameStatsConfig) {
    if (state->isOver()) {
        if (hasAnInputInfo()) {
            state->setNextState(getNextInputInfo());
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
CharacterStateID GameCharacter::getStateId() {
    return state->getStateId();
}

uint GameCharacter::receiveDamage(float damage, GameStatsConfig& gameStatsConfig) {
    if (gameStatsConfig.canEvade(race)) {
        std::cout << "Enemy fail attack" << std::endl;
    } else {
        float defense = gameStatsConfig.getDefense(body, shield, helmet);
        float realDamage = damage - defense;
        if (realDamage > 0) {
            life = (life - realDamage > 0) ? life - realDamage : 0;
        }
        std::cout << "Enemy attack damage: " << damage << std::endl;
        std::cout << "Character defense: " << defense << std::endl;
        std::cout << "Enemy real damage: " << realDamage << std::endl;
    }
    if (isDead()) {
        state = std::unique_ptr<State>(new DeadStateCharacter());
        body = BodyID::Ghost;
        shield = ShieldID::Nothing;
        weapon = WeaponID::Nothing;
        helmet = HelmetID::Nothing;
    }
    return life;
}

bool GameCharacter::isDead() {
    return life == 0;
}

bool GameCharacter::hasAnInputInfo() {
    return !queueInputs.empty();
}

InputInfo GameCharacter::getNextInputInfo() {
    return queueInputs.pop();
}

WeaponID GameCharacter::getWeapon() {
    return weapon;
}

GameCharacter::~GameCharacter()= default;

