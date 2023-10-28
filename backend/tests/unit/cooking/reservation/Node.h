#ifndef Node_H
#define Node_H

#include <iostream>
#include <vector>
#include <memory>
#include "Table.h"

class Node {
    public:
    std::shared_ptr<Table> table;
    std::vector<std::shared_ptr<Node>> neighbors;

    public:
    Node(std::shared_ptr<Table>);
    ~Node();
    std::vector<std::shared_ptr<Node>> getNeighbors();
    std::shared_ptr<Table> getTable();

};

#endif