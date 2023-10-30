#ifdef GENERALTABLE_CPP
#define GENERALTABLE_CPP
#include "GeneralTable.h"


GeneralTable::GeneralTable(int tableID) : Table(tableID){}

GeneralTable::~GeneralTable(){}

void GeneralTable::addReservation(){}

void GeneralTable::markTableOccupied(){}

bool GeneralTable::isTableAvailable()
{
    return false;
}

#endif