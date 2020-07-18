#include "AttackStateCreature.h"
#include "../Creature.h"
#include "../GameCharacter.h"
#include "StillStateCreature.h"
#include "PursuitStateCreature.h"

AttackStateCreature::~AttackStateCreature() = default;

AttackStateCreature::AttackStateCreature(uint enemyId) :
        enemyId(enemyId), enemyIsDead(false) {
    stateId = CharacterStateID::Attack;
}


void AttackStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    if (timeBetweenAttacks == 0) {
        timeBetweenAttacks = 20;
        std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
        try {
            aEnemy = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(enemyId));
            std::shared_ptr<Cell> creatureCell = aCreature->getActualCell();
            std::shared_ptr<Cell> enemyCell = aEnemy->getActualCell();
            if (aEnemy->isDead()) {
                enemyIsDead = true;
                finalized = true;
            } else {
                if (board.getDistance(creatureCell, enemyCell) == GameStatsConfig::getWeaponDistance(WeaponID::Nothing)) {
                    aEnemy->receiveDamage(GameStatsConfig::getDamage(aCreature->getCreatureId()),
                            WeaponID::Nothing);
                    if (aEnemy->isDead()) {
                        enemyIsDead = true;
                        finalized = true;
                    }
                } else {
                    aEnemy->setAttackBy(WeaponID::Nothing);
                    finalized = true;
                }
            }
        } catch (const std::out_of_range& e) {
            enemyIsDead = true;
            finalized = true;
        }
    } else {
        timeBetweenAttacks--;
    }
}

void AttackStateCreature::setNextState(InputInfo info) {
    if (enemyIsDead) {
        nextState = std::unique_ptr<State>(new StillStateCreature());
    } else {
        nextState = std::unique_ptr<State>(new PursuitStateCreature(enemyId));
    }
}

void AttackStateCreature::resetState() {}

bool AttackStateCreature::isOnPursuit(uint pursuitId) {
    return false;
}

bool AttackStateCreature::isAttacking() {
    return true;
}

bool AttackStateCreature::isMeditating() {
    return false;
}
