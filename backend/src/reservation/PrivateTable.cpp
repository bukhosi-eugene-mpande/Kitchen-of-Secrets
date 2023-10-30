#ifndef PRIVATETABLE_CPP
#define PRIVATETABLE_CPP

#include "PrivateTable.h"

PrivateTable::PrivateTable(int tableID) : Table(tableID) {}

PrivateTable::~PrivateTable(){}

void PrivateTable::addReservation()
{

}

void PrivateTable::markTableOccupied()
{
    
}

bool PrivateTable::isTableAvailable()
{
    return false;
}

#endif