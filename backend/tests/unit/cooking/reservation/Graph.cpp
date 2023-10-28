#include "Graph.h"

Graph::Graph(){ }

Graph::~Graph(){ }

void Graph::addNode(std::shared_ptr<Table> table){
    std::shared_ptr<Node> node = std::make_shared<Node>(table);
    nodes.push_back(node);
}

void Graph::removeNode(std::shared_ptr<Node> node){
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i] == node) {
            nodes.erase(nodes.begin() + i);
        }
    }
}

void Graph::addEdge(std::shared_ptr<Node> from, std::shared_ptr<Node> to){
    from->neighbors.push_back(to);
    to->neighbors.push_back(from);
}

void Graph::printGraph(){
    for (int i = 0; i < nodes.size(); i++) {
        std::cout << "Table " << nodes[i]->getTable()->getTableId() << " has neighbors: ";
        for (int j = 0; j < nodes[i]->getNeighbors().size(); j++) {
            std::cout << nodes[i]->getNeighbors()[j]->getTable()->getTableId() << " ";
        }
        std::cout << std::endl;
    }
}

