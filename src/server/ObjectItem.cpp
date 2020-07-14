#include "ObjectItem.h"

ObjectItem::ObjectItem(uint id, const Point &initialPoint, const std::shared_ptr<Cell> &initialCell, const DropItem& dropItem)
: GameObject(id, initialPoint, initialCell), amount(dropItem.getAmount()), itemId(dropItem.getId()) {
    std::string stringItemID = std::to_string((int)itemId);
    textureHashId = "ht00|h00|b00|s00|w00|i" + (stringItemID.size() == 2 ? stringItemID : "0" + stringItemID);
}

float ObjectItem::getMaxLife() {
    return 0;
}

void ObjectItem::update(std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {
    timeToBeRemove--;
}

CharacterStateID ObjectItem::getStateId() {
    return CharacterStateID::Still;
}

bool ObjectItem::isDead() {
    return false;
}

void ObjectItem::receiveDamage(float damage, WeaponID weaponId) {}

NPCInfo ObjectItem::interact(GameObject &character, InputInfo input) {
    return NPCInfo();
}

bool ObjectItem::isReadyToRemove() {
    return timeToBeRemove <= 0;
}

void ObjectItem::remove(Board &board) {
    getActualCell()->removeItem();
}

std::vector<DropItem> ObjectItem::getDrop() {
    return std::vector<DropItem>();
}

bool ObjectItem::isItem() {
    return true;
}

bool ObjectItem::canDropsItems() {
    return false;
}

ObjectItem::~ObjectItem() = default;

int ObjectItem::getAmount() const {
    return amount;
}

ItemsInventoryID ObjectItem::getItemId() const {
    return itemId;
}

void ObjectItem::take() {
    timeToBeRemove = 0;
}
