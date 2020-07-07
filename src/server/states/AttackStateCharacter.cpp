#include "AttackStateCharacter.h"
#include "../GameCharacter.h"
#include "StillStateCharacter.h"

AttackStateCharacter::~AttackStateCharacter() = default;

AttackStateCharacter::AttackStateCharacter(InputInfo info) : State(info) {}

void AttackStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    try {
        uint enemyId = board.getIdFromPoint(inputInfo.position);
        if (enemyId != 0) {
            std::shared_ptr<GameObject> aEnemy = gameObjects.at(enemyId);
            if (aEnemy->getBoardPosition().getPosition().distance(aCharacter->getBoardPosition().getPosition()) < 15) {
                aEnemy->receiveDamage(gameStatsConfig.getDamage(aCharacter->getRace(), aCharacter->getWeapon()), gameStatsConfig);
            }
        } else {
            finalized = true;
        }
    } catch (const std::out_of_range& e) {
        finalized = true;
    }
}

void AttackStateCharacter::setNextState(InputInfo info) {
    nextState = std::unique_ptr<State>(new StillStateCharacter(info));
}

void AttackStateCharacter::resetState() {

}

bool AttackStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool AttackStateCharacter::isAttacking() {
    return true;
}
