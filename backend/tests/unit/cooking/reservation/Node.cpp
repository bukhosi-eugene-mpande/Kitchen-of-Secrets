#include "Node.h"

Node::Node(std::shared_ptr<Table> table) {
    this->table = table;
}

Node::~Node() { }

std::vector<std::shared_ptr<Node>> Node::getNeighbors() {
    return neighbors;
}

std::shared_ptr<Table> Node::getTable() {
    return table;
}
