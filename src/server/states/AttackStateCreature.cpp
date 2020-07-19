#include "AttackStateCreature.h"
#include "../Creature.h"
#include "../GameCharacter.h"
#include "StillStateCreature.h"
#include "PursuitStateCreature.h"

AttackStateCreature::~AttackStateCreature() = default;

AttackStateCreature::AttackStateCreature() : State(),
        enemyId(enemyId), enemyIsDead(false) {
    stateId = StateID::Attack;
}

void AttackStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    if (timeBetweenAttacks == 0) {
        timeBetweenAttacks = 20;
        std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
        try {
            aEnemy = gameObjects.at(enemyId);
            if (aEnemy->isDead()) {
                enemyIsDead = true;
                finalized = true;
                return;
            }
        } catch (const std::exception& e) {
            enemyIsDead = true;
            finalized = true;
            return;
        }
        std::shared_ptr<Cell> creatureCell = aCreature->getActualCell();
        std::shared_ptr<Cell> enemyCell = aEnemy->getActualCell();

        if (board.getDistance(creatureCell, enemyCell) == GameStatsConfig::getWeaponDistance(WeaponID::Nothing)) {
            aEnemy->receiveDamage(GameStatsConfig::getDamage(aCreature->getCreatureId()),
                    WeaponID::Nothing);
        } else {
            if (aEnemy != nullptr) {
                aEnemy->setInteractWeapon(WeaponID::Nothing);
            }
            finalized = true;
        }
    } else {
        timeBetweenAttacks--;
    }
}

bool AttackStateCreature::isOnPursuit(uint pursuitId) {
    return false;
}

bool AttackStateCreature::isAttacking() {
    return true;
}

bool AttackStateCreature::isMeditating() {
    return false;
}

StateID AttackStateCreature::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (!enemyIsDead) {
        nextStateId = StateID::Pursuit;
    }
    return nextStateId;
}

StateID AttackStateCreature::getResetStateID() {
    return StateID::Still;
}

void AttackStateCreature::init(InputInfo aInputInfo) {
    enemyId;
    enemyIsDead = false;
    timeBetweenAttacks = 0;
    aEnemy = nullptr;
}
