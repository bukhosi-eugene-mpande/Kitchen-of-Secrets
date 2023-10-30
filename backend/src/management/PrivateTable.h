#ifndef PRIVATE_TABLE_H
#define PRIVATE_TABLE_H

#include "Table.h"

class PrivateTable : public Table {
    public:
        PrivateTable(Engine* engine, int tableID);
        ~PrivateTable();
};

#endif