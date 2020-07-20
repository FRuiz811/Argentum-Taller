#include "Node.h"

#include <utility>

Node::Node(int parent, int g, int h, std::shared_ptr<Cell> aCell) :
parent(parent), g(g), h(h), cell(std::move(aCell)) {
    id = std::stoi(std::to_string(cell->getX() + 1) + std::to_string(cell->getY() + 1));
}

int Node::getG() const {
    return g;
}

void Node::setG(int g) {
    Node::g = g;
}

int Node::getH() const {
    return h;
}

void Node::setH(int h) {
    Node::h = h;
}

const std::shared_ptr<Cell> &Node::getCell() const {
    return cell;
}

int Node::getF() {
    return g + h;
}

int Node::getId() const {
    return id;
}

bool operator==(const Node& node1, const Node &node2) {
    return node1.getCell() == node2.getCell();
}

bool operator!=(const Node& node1, const Node &node2) {
    return !(node1 == node2);
}

void Node::setParent(int aParent) {
    parent = aParent;
}

int Node::getParent() const {
    return parent;
}

Node::~Node() = default;
