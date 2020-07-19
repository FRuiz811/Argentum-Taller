#include "AttackStateCharacter.h"
#include "../GameCharacter.h"

AttackStateCharacter::~AttackStateCharacter() = default;

AttackStateCharacter::AttackStateCharacter() : StateCharacter() {
    stateId = StateID::Attack;
}

void AttackStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    if (timeBetweenAttacks == 0) {
        timeBetweenAttacks = 30;
        std::shared_ptr<Cell> enemyCell = board.getCellFromPoint(inputInfo.position);
        if (enemyCell->getGameObjectId() != 0 && enemyCell != aCharacter->getActualCell()) {
            try {
                aEnemy = gameObjects.at(enemyCell->getGameObjectId());
                if (!aEnemy->isDead() &&
                    board.getDistance(aCharacter->getActualCell(), enemyCell) <= GameStatsConfig::getWeaponDistance(aCharacter->getWeapon()) &&
                    aCharacter->canPerformAttack() && aEnemy->canBeAttacked(aCharacter->getLevel())) {

                    float damage = GameStatsConfig::getDamage(aCharacter->getRace(), aCharacter->getWeapon());
                    aCharacter->consumeMana();
                    aEnemy->receiveDamage(damage, aCharacter->getWeapon());
                    aCharacter->gainExp(aEnemy->isDead() ?
                        GameStatsConfig::getAdditionalExp(damage, aEnemy->getMaxLife(), aCharacter->getLevel(), aEnemy->getLevel()) :
                        GameStatsConfig::getExp(damage, aCharacter->getLevel(), aEnemy->getLevel()));
                    if (aCharacter->getExp() >= GameStatsConfig::getNextLevelLimit(aCharacter->getLevel())) {
                        aCharacter->upLevel();
                    }
                    enemyReceiveDamage = true;
                }
            } catch (const std::exception& e) {
                std::cout << "Cannot get Enemy" << std::endl;
            }
        }
        if (!enemyReceiveDamage) {
            finalized = true;
        }
    } else {
        timeBetweenAttacks--;
        if (timeBetweenAttacks == 0) {
            finalized = true;
            if (aEnemy != nullptr) {
                aEnemy->setInteractWeapon(WeaponID::Nothing);
            }
        }
    }
}

bool AttackStateCharacter::isAttacking() {
    return true;
}

bool AttackStateCharacter::isMeditating() {
    return false;
}

StateID AttackStateCharacter::getNextStateID(InputInfo info) {
    StateID nextStateId = StateID::Still;
    if (info.input == InputID::up || info.input == InputID::down ||
        info.input == InputID::left || info.input == InputID::right) {
        nextStateId = StateID::Move;
    }
    return nextStateId;
}

StateID AttackStateCharacter::getResetStateID() {
    return StateID::Still;
}

void AttackStateCharacter::init(InputInfo aInputInfo) {
    inputInfo = aInputInfo;
    finalized = false;
    aEnemy = nullptr;
    timeBetweenAttacks = 0;
    enemyReceiveDamage = false;
}
