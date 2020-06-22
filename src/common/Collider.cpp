//
// Created by victorbelosevich on 21/6/20.
//

#include "Collider.h"

Collider::Collider() = default;

Collider::~Collider() = default;

bool Collider::checkCollision(const Position &first, const Position &second) {
    bool collision = true;
    if(first.getBottom() <= second.getTop()) {
        collision = false;
    }
    if (first.getTop() >= second.getBottom()) {
        collision = false;
    }
    if (first.getRight() <= second.getLeft()) {
        collision = false;;
    }
    if (first.getLeft() >= second.getRight()) {
       collision = false;
    }
    return collision;
}
