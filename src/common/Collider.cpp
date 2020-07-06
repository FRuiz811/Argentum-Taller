#include "Collider.h"

Collider::Collider() = default;

Collider::~Collider() = default;

bool Collider::checkCollision(const Position &first, const Position &second) {
    bool collision = false;
    if ((first.getRight() > second.getLeft() && first.getRight() < second.getRight()) ||
            (first.getLeft() < second.getRight() && first.getLeft() > second.getLeft())){
        if (first.getMiddle() > second.getTop() && first.getMiddle() < second.getBottom()) {
            collision = true;
        }
//        if ((first.getTop() < second.getMiddle() && first.getTop() > second.getTop()) ||
//                (first.getBottom() > second.getMiddle() && first.getBottom() > second.getTop() && first.getBottom() < second.getBottom())) {
//            collision = true;
//        }

    }
    return collision;
}

bool Collider::checkStaticCollision(const Position &first, const Position &second) {
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
