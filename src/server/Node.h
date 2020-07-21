#ifndef ARGENTUM_TALLER_NODE_H
#define ARGENTUM_TALLER_NODE_H


#include <memory>
#include "Cell.h"

class Node {
private:
    int parent;
    int g;
    int h;
    int id;
    std::shared_ptr<Cell> cell;
public:
    Node(int parent, int g, int h, std::shared_ptr<Cell> cell);

    const std::shared_ptr<Cell> &getCell() const;

    friend bool operator==(const Node& node1, const Node& node2);

    friend bool operator!=(const Node& node1, const Node& node2);

    int getF();

    void setParent(int parent);

    int getParent() const;

    int getId() const;

    int getG() const;

    void setG(int g);

    int getH() const;

    void setH(int h);

    virtual ~Node();

};


#endif //ARGENTUM_TALLER_NODE_H
