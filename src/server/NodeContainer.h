#ifndef ARGENTUM_TALLER_NODECONTAINER_H
#define ARGENTUM_TALLER_NODECONTAINER_H


#include <map>
#include "Node.h"

class NodeContainer {
private:
    std::map<int, Node> nodes;
public:
    NodeContainer();

    void insert(const Node& aNode);

    bool has(const Node& aNode);

    Node getBestNode();

    virtual ~NodeContainer();

    void modifyNode(int i, Node &node);

    Node &get(int i);
};


#endif //ARGENTUM_TALLER_NODECONTAINER_H
