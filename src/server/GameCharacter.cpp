#include <iostream>
#include <utility>
#include "GameCharacter.h"
#include "GameStatsConfig.h"
#include "../common/Random.h"
#include "ItemTranslator.h"

PlayerInfo GameCharacter::getPlayerInfo() {
    return PlayerInfo(id, point, goldAmount, life, mana, textureHashId, direction, GameStatsConfig::getMaxGold(level),
                      GameStatsConfig::getMaxHealth(race, gameClass, level),
                      GameStatsConfig::getMaxMana(race, gameClass, level),
                      exp,GameStatsConfig::getNextLevelLimit(level), level,
                      getStringInventory(), statePool.getStateId(), interactWeapon);
}

GameCharacter::GameCharacter(uint id, RaceID aRace, GameClassID aClass, std::shared_ptr<Cell> initialCell, Point initialPoint):
        GameObject(id, initialPoint, std::move(initialCell)), race(aRace), gameClass(aClass), statePool(this), queueInputs(true), inventory() {

    this->life = GameStatsConfig::getMaxHealth(race, gameClass, level);
    this->mana = GameStatsConfig::getMaxMana(race, gameClass, level);
    this->goldAmount = 100;
    this->exp = 0;
    this->direction = Direction::down;
    this->textureHashId = updateTextureHashId(); //Solo debería tener la cabeza correspondiente y su cuerpo. "ht00|h03|b01|s00|w00"
}

void GameCharacter::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {
    this->infoInteracting.type = 0;
    statePool.updateState(getNextInputInfo());
    statePool.getActualState()->performTask(id, gameObjects, board);
    this->textureHashId = updateTextureHashId();
    updateHealthAndMana();
}

std::string GameCharacter::updateTextureHashId() {
    std::string equipment;
    std::string idHelmet = std::to_string((int)this->helmet);
    equipment += "ht";
    if (idHelmet.size() == 1)
        equipment += "0";
    equipment += idHelmet + "|";
    equipment += "h";
    if (!isDead()){
        std::string idHead = std::to_string((int)this->race);
        if (idHead.size() == 1)
            equipment += "0";
        equipment += idHead + "|";
    } else {
        equipment += "00|";
    }
    equipment += "b";
    if (this->body == BodyID::Nothing || (this->body == BodyID::Ghost && !isDead())) {
        this->body = (BodyID)(Random::get(1,3));
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
    return equipment;
}

std::string GameCharacter::getStringInventory() const {
    return inventory.getStringInventory();
}

void GameCharacter::equipItem(int itemToEquip) {
    ItemsInventoryID idItem = inventory.getItem(itemToEquip-1);
    if (idItem == ItemsInventoryID::Nothing)
        return;
    ItemInfo info = GameStatsConfig::getItem(idItem);
    ItemsInventoryID item = ItemsInventoryID::Nothing;
    if (info.type == "Weapon") {
        WeaponID newWeapon = ItemTranslator::itemToWeapon(idItem);
        item = ItemTranslator::weaponToItem(this->weapon);
        this->weapon = newWeapon;
    } else if (info.type == "Body") {
        BodyID newBody = ItemTranslator::itemToBody(idItem);
        item = ItemTranslator::bodyToItem(this->body);
        this->body = newBody;
    } else if(info.type == "Shield") {
        ShieldID newShield = ItemTranslator::itemToShield(idItem);
        item = ItemTranslator::shieldToItem(this->shield);
        this->shield = newShield;
    } else if(info.type == "Helmet") {
        HelmetID newHelmet = ItemTranslator::itemToHelmet(idItem);
        item = ItemTranslator::helmetToItem(this->helmet);
        this->helmet = newHelmet;
    } else if(info.type == "Potion") {
        this->consumePotion(info);
    }
    this->inventory.removeItem(idItem);
    this->inventory.addItem(item);
}

void GameCharacter::unequipItem(int itemToUnequip) {
    ItemsInventoryID item = ItemsInventoryID::Nothing;
    if (!inventoryIsFull()) {
        switch (itemToUnequip) {
            case 0:
                item = ItemTranslator::helmetToItem(this->helmet);
                this->helmet = HelmetID::Nothing;
                break;
            case 1:
                item = ItemTranslator::weaponToItem(this->weapon);
                this->weapon = WeaponID::Nothing;
                break;
            case 2:
                item = ItemTranslator::shieldToItem(this->shield);
                this->shield = ShieldID::Nothing;
                break;
        }
    }
    this->inventory.removeItem(ItemsInventoryID::Nothing);
    this->inventory.addItem(item);
}

void GameCharacter::consumePotion(const ItemInfo& potion) {
    uint maxMana = GameStatsConfig::getMaxMana(this->race, this->gameClass,this->level);
    uint maxHealth = GameStatsConfig::getMaxHealth(this->race, this->gameClass,this->level);
    mana = mana + potion.manaRestored > maxMana ? maxMana : mana + potion.manaRestored;
    life = life + potion.healthRestored > maxHealth ? maxHealth : life + potion.healthRestored;
}

RaceID GameCharacter::getRace() const {
    return race;
}

uint GameCharacter::getGoldAmount() {
    return goldAmount;
}

float GameCharacter::getExp() const {
    return exp;
}

InputQueue &GameCharacter::getQueueInputs() {
    return queueInputs;
}
CharacterStateID GameCharacter::getStateId() {
    return statePool->getStateId();
}

void GameCharacter::receiveDamage(float damage, WeaponID weaponId) {
    setInteractWeapon(weaponId);
    if (GameStatsConfig::canEvade(race)) {
        std::cout << "Enemy fail attack" << std::endl;
    } else {
        float defense = GameStatsConfig::getDefense(body, shield, helmet);
        float realDamage = damage - defense;
        if (realDamage > 0) {
            life = (life - realDamage > 0) ? life - realDamage : 0;
        }
        std::cout << "Enemy attack damage: " << damage << std::endl;
        std::cout << "Character defense: " << defense << std::endl;
        std::cout << "Enemy real damage: " << realDamage << std::endl;
    }
    if (isDead()) {
        this->mana = 0;
        body = BodyID::Ghost;
        shield = ShieldID::Nothing;
        weapon = WeaponID::Nothing;
        helmet = HelmetID::Nothing;
    }
}

bool GameCharacter::isDead() {
    return life == 0;
}

bool GameCharacter::hasAnInputInfo() {
    return !queueInputs.empty();
}

InputInfo GameCharacter::getNextInputInfo() {
    InputInfo info;
    info.input = InputID::nothing;
    if (hasAnInputInfo()) {
        info = queueInputs.pop();
    }
    return info;
}

WeaponID GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::cure(){
    this->life = GameStatsConfig::getMaxHealth(race,gameClass, level);
    this->mana = GameStatsConfig::getMaxMana(race,gameClass, level);

}

NPCInfo GameCharacter::interact(GameObject& character, InputInfo input) {
    NPCInfo info;
    return info;
}

bool GameCharacter::isReadyToRemove() {
    return false;
}

void GameCharacter::remove(Board &board) {
    cell->free();
}

void GameCharacter::gainExp(float newExp) {
    exp += newExp;
}

float GameCharacter::getMaxLife() {
    return GameStatsConfig::getMaxHealth(race, gameClass, level);
}

bool GameCharacter::inventoryIsFull() {
    return inventory.isFull();
}

bool GameCharacter::addItemToInventory(ItemsInventoryID aItemInventoryId) {
   return inventory.addItem(aItemInventoryId);
}

void GameCharacter::setGoldAmount(uint goldAmount) {
    GameCharacter::goldAmount = goldAmount;
}

ItemsInventoryID GameCharacter::removeItemFromInventory(ItemsInventoryID aItemToRemove) {
    return inventory.removeItem(aItemToRemove);
}

void GameCharacter::gainGold(int aGoldAmount) {
    goldAmount += aGoldAmount;
}

std::vector<DropItem> GameCharacter::getDrop() {
    std::vector<DropItem> dropsItems;
    if (isDead()) {
        for (auto &aInventoryItem : inventory.getInventoryItems()) {
            if (aInventoryItem != ItemsInventoryID::Nothing) {
                dropsItems.emplace_back(aInventoryItem, 1);
            }
        }
        int diffGold = goldAmount - GameStatsConfig::getMaxGold(level);
        if (diffGold > 0) {
            goldAmount = GameStatsConfig::getMaxGold(level);
            dropsItems.emplace_back(ItemsInventoryID::Gold, diffGold);
        }
        inventory.clear();
    } else {
        dropsItems.emplace_back(itemToDrop, 1);
        itemToDrop = ItemsInventoryID::Nothing;
    }
    return dropsItems;
}

bool GameCharacter::isItem() {
    return false;
}

bool GameCharacter::canDropsItems() {
    return (isDead() && !inventory.isEmpty()) || itemToDrop != ItemsInventoryID::Nothing;
}

void GameCharacter::consumeMana() {
    if (weapon != WeaponID::Nothing) {
        mana -= GameStatsConfig::getWeaponCost(weapon);
    }
}

void GameCharacter::upLevel() {
    level++;
    life = getMaxLife();
    mana = GameStatsConfig::getMaxMana(race, gameClass, level);
}

bool GameCharacter::canPerformAttack() {
    return weapon != WeaponID::Nothing && GameStatsConfig::getWeaponCost(weapon) <= mana;
}

void GameCharacter::updateHealthAndMana() {
    if (!isDead()) {
        float manaMax = GameStatsConfig::getMaxMana(race, gameClass, level);
        float lifeIncrement = GameStatsConfig::getRecoveryHealth(race);
        life = life + lifeIncrement > getMaxLife() ? getMaxLife() : lifeIncrement + life;
        float manaIncrement = statePool->isMeditating() ?
                              GameStatsConfig::getRecoveryManaMeditation(race, gameClass) :
                              GameStatsConfig::getRecoveryMana(race);
        mana = mana + manaIncrement > manaMax ? manaMax : mana + manaIncrement;
    }
}

bool GameCharacter::takeItem(ItemsInventoryID anItemId, int amount) {
    bool canTake;
    if (anItemId == ItemsInventoryID::Gold) {
        goldAmount += amount;
        canTake = true;
    } else {
        canTake = inventory.addItem(anItemId);
    }
    return canTake;
}

void GameCharacter::dropItem(int index) {
    ItemsInventoryID itemToRemove = inventory.getItem(index);
    if (itemToRemove != ItemsInventoryID::Nothing) {
        itemToDrop =  this->inventory.removeItem(itemToRemove);
    }
}

bool GameCharacter::canBeAttacked(int enemyLevel) const {
    return GameStatsConfig::canAttack(this->level, enemyLevel);
}

GameCharacter::~GameCharacter()= default;
