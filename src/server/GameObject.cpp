#include "GameObject.h"

//GameObject::GameObject() : movimiento(Movimiento(Position(-1,-1))),  estado(Estado(0, 0)){}
//	Position pos(-1,-1);
//	Movimiento mov(pos);
//	movimiento = mov;
//	Estado est(0,0);
//	estado = est;
//}
GameObject::GameObject(GameObject&& other) {
    std::swap(position, other.position);
}

GameObject::GameObject(Position aPosition): position(std::move(aPosition)){

}

const Position &GameObject::getPosition() const {
    return position;
}

GameObject::GameObject() = default;

GameObject::~GameObject()= default;