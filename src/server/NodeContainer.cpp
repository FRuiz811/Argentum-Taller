#include "NodeContainer.h"

NodeContainer::NodeContainer() = default;

NodeContainer::~NodeContainer() = default;

void NodeContainer::insert(const Node& aNode) {
    nodes.insert(std::pair<int, Node>(aNode.getId(), aNode));
}

bool NodeContainer::has(const Node& aNode) {
    bool insideContainer = true;
    try {
        nodes.at(aNode.getId());
    } catch (std::exception &e) {
        insideContainer = false;
    }
    return insideContainer;
}

Node NodeContainer::getBestNode() {
    auto iter = nodes.begin();
    int bestF = 0;
    Node aNode = (*iter).second;
    while (iter != nodes.end()) {
        if (bestF == 0 || (*iter).second.getF() < bestF) {
            bestF = (*iter).second.getF();
            aNode = (*iter).second;
        }
        iter++;
    }
    nodes.erase(aNode.getId());
    return aNode;
}

void NodeContainer::modifyNode(int id, Node &aNode) {
    Node &innerNode = nodes.at(id);
    if (aNode.getG() + 1 < innerNode.getG()) {
        innerNode.setG(aNode.getG() + 1);
        innerNode.setParent(aNode.getId());
    }
}

Node &NodeContainer::get(int id) {
    return nodes.at(id);
}
