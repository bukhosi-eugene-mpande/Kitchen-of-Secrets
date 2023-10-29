#ifndef FloorIterator_H
#define FloorIterator_H

#include <iostream>
#include <vector>

#include <memory>
#include <queue>
#include "Graph.h"
#include "Table.h"

class FloorIterator {
    protected:
        int level;
        std::shared_ptr<Graph> list;
        std::shared_ptr<Table> firstTable;
        std::shared_ptr<Table> currentTable;
        std::vector<std::shared_ptr<Table>> visited;
        std::queue<std::shared_ptr<Table>> friends;

    public:
        FloorIterator(std::shared_ptr<Graph> list);

        ~FloorIterator();

        std::shared_ptr<Table> first();

        std::shared_ptr<Table> next();

        bool isDone();

        std::shared_ptr<Table> current();

        bool visted(std::shared_ptr<Table> table);
};

#endif