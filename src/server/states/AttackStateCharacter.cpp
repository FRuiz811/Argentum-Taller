#include "AttackStateCharacter.h"
#include "../GameCharacter.h"
#include "StillStateCharacter.h"
#include "MoveStateCharacter.h"
#include "EquipStateCharacter.h"

AttackStateCharacter::~AttackStateCharacter() = default;

AttackStateCharacter::AttackStateCharacter(InputInfo info) : State(info) {}

void AttackStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    try {
        std::shared_ptr<Cell> enemyCell = board.getCellFromPoint(inputInfo.position);
        if (enemyCell->getGameObjectId() != 0) {
            std::shared_ptr<GameObject> aEnemy = gameObjects.at(enemyCell->getGameObjectId());
            if (!aEnemy->isDead() && board.getDistance(aCharacter->getActualCell(), enemyCell) == 1) {
                aEnemy->receiveDamage(GameStatsConfig::getDamage(aCharacter->getRace(), aCharacter->getWeapon()));
            }
        } else {
            finalized = true;
        }
    } catch (const std::out_of_range& e) {
        finalized = true;
    }
}

void AttackStateCharacter::setNextState(InputInfo info) {
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        this->nextState = std::unique_ptr<State>(new MoveStateCharacter(info));
    } else if (info.input == InputID::equipItem) {
        nextState = std::unique_ptr<State>(new EquipStateCharacter(info));
    } else {
        nextState = std::unique_ptr<State>(new StillStateCharacter(info));
    }
}

void AttackStateCharacter::resetState() {
    nextState = std::unique_ptr<State>(new StillStateCharacter());
}

bool AttackStateCharacter::isOnPursuit(uint pursuitId) {
    return false;
}

bool AttackStateCharacter::isAttacking() {
    return true;
}
