#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <memory>
#include <vector>

#include "Node.h"

class Graph {
    public:
        std::vector<std::shared_ptr<Node>> nodes;

    public:
        Graph();

        ~Graph();

        void addNode(std::shared_ptr<Table> table);

        void removeNode(std::shared_ptr<Node> node);

        void addEdge(std::shared_ptr<Node> from, std::shared_ptr<Node> to);

        void printGraph();
};

#endif