#include "PursuitStateCreature.h"
#include "StillStateCreature.h"
#include "../Creature.h"
#include "../GameCharacter.h"
#include "AttackStateCreature.h"
#include <bits/stdc++.h>

PursuitStateCreature::~PursuitStateCreature() = default;

PursuitStateCreature::PursuitStateCreature(uint id) : pursuitId(id) {
    stateId = CharacterStateID::Move;
}

void PursuitStateCreature::performTask(uint id, std::unordered_map<uint, std::shared_ptr<GameObject>> &gameObjects,
                                       Board &board, GameStatsConfig &gameStatsConfig) {

    std::shared_ptr<Creature> aCreature = std::dynamic_pointer_cast<Creature>(gameObjects.at(id));
    std::shared_ptr<GameCharacter> aCharacter = std::dynamic_pointer_cast<GameCharacter>(gameObjects.at(pursuitId));
    Position& characterPosition = aCharacter->getBoardPosition().getPosition();
    if (board.isInsideNest(characterPosition, aCreature->getBoardPosition().getNestId())) {
        float distance = characterPosition.distance(aCreature->getBoardPosition().getPosition());
        std::cout << std::to_string(distance) << std::endl;
        if (distance < 80) {
            canAttack = true;
            finalized = true;
        } else {
            if (!movement.hasStart()) {
                findNextPosition(aCreature, characterPosition, board, gameStatsConfig);
            } else {
                Position newPosition = movement.doStep();
                if (!board.checkCreaturesCollisions(aCreature->getBoardPosition(), newPosition, aCreature->getId())) {
                    aCreature->getBoardPosition().setPosition(newPosition);
                } else {
                    movement.stop();
                }
                if (movement.isOver()) {
                    movement.reset();
                }
            }
        }
    } else {
        finalized = true;
    }


}

void PursuitStateCreature::findNextPosition(const std::shared_ptr<Creature>& creature, Position& characterPosition, Board& board, GameStatsConfig& gameStatsConfig) {
    Position &actualPosition = creature->getBoardPosition().getPosition();
    float distance = gameStatsConfig.getDistance();
    std::vector<std::tuple<uint, Position, Direction>> adjacentPosition;
    //Agrego las posiciones adyacentes a la posicion actual.
    Position aPosition = Position(actualPosition.getPoint().x, actualPosition.getPoint().y - distance, actualPosition.getWidth(), actualPosition.getHeight());
    adjacentPosition.emplace_back(std::make_tuple(characterPosition.distance(aPosition), aPosition, Direction::up));
    aPosition = Position(actualPosition.getPoint().x + distance, actualPosition.getPoint().y, actualPosition.getWidth(), actualPosition.getHeight());
    adjacentPosition.emplace_back(std::make_tuple(characterPosition.distance(aPosition), aPosition, Direction::right));
    aPosition = Position(actualPosition.getPoint().x, actualPosition.getPoint().y + distance, actualPosition.getWidth(), actualPosition.getHeight());
    adjacentPosition.emplace_back(std::make_tuple(characterPosition.distance(aPosition), aPosition, Direction::down));
    aPosition = Position(actualPosition.getPoint().x - distance, actualPosition.getPoint().y, actualPosition.getWidth(), actualPosition.getHeight());
    adjacentPosition.emplace_back(std::make_tuple(characterPosition.distance(aPosition), aPosition, Direction::left));

    //Ordeno el vector y obtengo la posicion valida cuya distancia al objetivo sea menor.
    std::sort(adjacentPosition.begin(), adjacentPosition.end(),
            [](std::tuple<int, Position, Direction> const &t1, std::tuple<int, Position, Direction>  const &t2) {
                return std::get<0>(t1) < std::get<0>(t2);
    });

    for (auto &tuple : adjacentPosition) {
        if (!board.checkCreaturesCollisions(creature->getBoardPosition(), std::get<1>(tuple), creature->getId())) {
            movement.start(std::get<1>(tuple), std::get<2>(tuple), gameStatsConfig, creature->getCreatureId());
            creature->setDirection(std::get<2>(tuple));
            break;
        }
    }
}

void PursuitStateCreature::setNextState(InputInfo info) {
    if (canAttack) {
        nextState = std::unique_ptr<State>(new AttackStateCreature(pursuitId));
    } else {
        nextState = std::unique_ptr<State>(new StillStateCreature());
    }
}

void PursuitStateCreature::resetState() {}

bool PursuitStateCreature::isOnPursuit(uint aPursuitId) {
    return pursuitId == aPursuitId;
}

bool PursuitStateCreature::isAttacking() {
    return false;
}
