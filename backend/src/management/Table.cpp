#include "Table.h"

Table::Table(Engine* engine, int tableID) : GameComponent(engine) {
    this->tableID = tableID;
    isOccupied = false;
}

Table::~Table() {}

int Table::getTableID() {
    return tableID;
}

void Table::setTableID(int tableID) {
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

