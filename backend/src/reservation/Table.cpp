#ifndef TABLE_CPP
#define TABLE_CPP

#include "Table.h"

Table::Table(Engine* engine, int tableID, int seat) {
    isOccupied = false;
    this->tableID = tableID;
    this->seat = seat;
}

Table::~Table() {}

int Table::getTableID()
{
    return tableID;
}

void Table::setTableID(int tableID)
{
    this->tableID = tableID;
}

void Table::placeTable(int xCoord, int yCoord) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
}

bool Table::getIsOccupied() {
    return isOccupied;
}

void Table::setIsOccupied(bool isOccupied) {
    this->isOccupied = isOccupied;
}

#endif