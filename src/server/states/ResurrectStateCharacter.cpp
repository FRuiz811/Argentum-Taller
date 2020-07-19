#include <GameCharacter.h>
#include "ResurrectStateCharacter.h"

ResurrectStateCharacter::~ResurrectStateCharacter() = default;

ResurrectStateCharacter::ResurrectStateCharacter() : StateCharacter() {
    finalized = false;
    stateId = StateID::Resurrect;
}

void ResurrectStateCharacter::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects, Board &board) {

    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(id));
    std::shared_ptr<Cell> characterCell = aCharacter->getActualCell();
    if (aPriestCell == nullptr) {
        aPriestCell = board.getCloserPriest(characterCell);
    }
    if (!movement.hasStart()) {
            if (board.getDistance(characterCell, aPriestCell) == 1) {
                finalized = true;
                aCharacter->setDirection(board.getDirection(characterCell, aPriestCell));
            } else {
                std::shared_ptr<Cell> newCell;
                newCell = board.getBestCell(characterCell, aPriestCell);
                if (newCell != characterCell) {
                    Direction aDirection = board.getDirection(characterCell, newCell);
                    aCharacter->setDirection(aDirection);
                    movement.start(board.getPointFromCell(aCharacter->getActualCell()), aDirection, aCharacter->getRace());
                    aCharacter->getActualCell()->free();
                    newCell->occupied(id);
                    aCharacter->setCell(newCell);
                }
            }
    } else {
        aCharacter->setPoint(movement.doStep());
        if (movement.isOver()) {
            movement.reset();
        }
    }

}

StateID ResurrectStateCharacter::getNextStateID(InputInfo info) {
    return StateID::Still;
}

StateID ResurrectStateCharacter::getResetStateID() {
    return StateID::Still;
}

bool ResurrectStateCharacter::isAttacking() {
    return false;
}

bool ResurrectStateCharacter::isMeditating() {
    return false;
}

void ResurrectStateCharacter::init(InputInfo aInputInfo) {
    aPriestCell = nullptr;
    finalized = false;
    movement.reset();
}
