#ifndef TABLE_CPP
#define TABLE_CPP

#include "Table.h"

Table::Table(int tableID)
{
    this->tableID = tableID;
}

Table::~Table(){}

int Table::getTableID()
{
    return tableID;
}

void Table::setTableID(int tableID)
{
    this->tableID = tableID;
}

#endif