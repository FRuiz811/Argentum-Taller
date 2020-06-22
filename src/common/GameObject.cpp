#include "GameObject.h"

//GameObject::GameObject() : movimiento(Movimiento(Position(-1,-1))),  estado(Estado(0, 0)){}
//	Position pos(-1,-1);
//	Movimiento mov(pos);
//	movimiento = mov;
//	Estado est(0,0);
//	estado = est;
//}
GameObject::GameObject(GameObject&& other)  noexcept {
    std::swap(position, other.position);
}

GameObject::GameObject(Position aPosition): position(std::move(aPosition)){

}

Position &GameObject::getPosition() {
    return position;
}

GameObject &GameObject::operator=(GameObject &&other) noexcept{
    if (&other == this) {
        return *this;
    }
    std::swap(position, other.position);
    return *this;
}

void GameObject::setPosition(const Position &position) {
    GameObject::position = position;
}

GameObject::GameObject() = default;

GameObject::~GameObject()= default;