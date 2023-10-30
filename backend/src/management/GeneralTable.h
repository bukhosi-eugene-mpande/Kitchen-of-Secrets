#ifndef GENERAL_TABLE_H
#define GENERAL_TABLE_H

#include "Table.h"

class GeneralTable: public Table {
    public:
        GeneralTable(Engine* engine, int tableID);
        ~GeneralTable();
};

#endif