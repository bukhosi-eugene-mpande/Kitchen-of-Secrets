#include "FloorIterator.h"

FloorIterator::FloorIterator(std::shared_ptr<Graph> list) {
    this->level = 0;
    this->list = list;
    this->firstTable = this->list->nodes[0]->getTable();
    this->currentTable = this->firstTable;
    this->visited.resize(list->nodes.size());
}

FloorIterator::~FloorIterator() { }

std::shared_ptr<Table> FloorIterator::first() {
    return this->firstTable;
}

std::shared_ptr<Table> FloorIterator::next() {
    if (!isDone() && level<list->nodes.size()) {
        if (friends.empty()) {
            do {
                int i = level;
                std::queue<std::shared_ptr<Table>> temp;
                temp.push(list->nodes[i]->getTable());
                for(int j =0;j<list->nodes[i]->getNeighbors().size();j++){
                    temp.push(list->nodes[i]->getNeighbors()[j]->getTable());
                }
                
                for(int j=0;j<temp.size();j++){
                    if(!visted(temp.front())){
                        friends.push(temp.front());
                        visited.push_back(temp.front());
                    }
                }
                level++;

            }while(friends.empty());
            this->currentTable = friends.front();
            friends.pop();
            return currentTable;
        }else{
            this->currentTable = friends.front();
            friends.pop();
            return currentTable;
        }
    }
    return nullptr;
}

bool FloorIterator::isDone() {
    for (int i = 0; i < list->nodes.size(); i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

std::shared_ptr<Table> FloorIterator::current() {
    return this->currentTable;
}

bool FloorIterator::visted(std::shared_ptr<Table> table) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == table) {
            return true;
        }
    }
    return false;
}

