#include "Creature.h"
#include "StillStateCreature.h"

Creature::Creature() = default;

void Creature::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board,
                      GameStatsConfig &gameStatsConfig) {

}

Creature::Creature(uint id, CreatureID creatureId, Point aPoint) :
GameObject(id), creatureId(creatureId) {
    switch (creatureId) {
        case CreatureID::Goblin:
            this->position = Position(aPoint, 24, 30);
            this->textureHashId = "ht00|h00|b11|s00|w00";
            break;
        case CreatureID::Skeleton:
            this->position = Position(aPoint, 25, 52);
            this->textureHashId = "ht00|h00|b12|s00|w00";
            break;
        case CreatureID::Spider:
            this->position = Position(aPoint, 53, 35);
            this->textureHashId = "ht00|h00|b13|s00|w00";
            break;
        case CreatureID::Zombie:
            this->position = Position(aPoint, 25, 61);
            this->textureHashId = "ht00|h06|b14|s00|w00";
            break;
    }
    this->state = std::unique_ptr<State>(new StillStateCreature());
}

Creature::~Creature() = default;
