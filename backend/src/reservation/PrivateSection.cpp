#ifndef PRIVATESECTION_CPP
#define PRIVATESECTION_CPP

#include "PrivateSection.h"

PrivateSection::PrivateSection(int seat) : SeatingPlan() {
    seat = 2;
    // this->seat = seat;
    for (int i = 0; i < PRIVATE_TABLE_CAPACITY; ++i) {
        PrivateTable* newTable = new PrivateTable(engine, i, seat); // Initialize tables with the seat value.
        privateTables.push_back(newTable);
    }
}

// PrivateSection::PrivateSection(){
//     seat = 2;
// }

PrivateSection::~PrivateSection(){}

void PrivateSection::seatCustomers(Customer *customer)
{
    this->customer = customer;
}

void PrivateSection::combineTables(int tableID1, int tableID2) //id 1 == deletes table , id2 == table to be combined
{
    seat *= 2;
    // Modify table creation to include the updated seat value.
    // PrivateTable* newTable = new PrivateTable(engine, tableID2, seat);
    // newTable->setTableID(tableID1);
    privateTables[tableID2]->seat = seat;
}

void PrivateSection::seperateTables(int tableID)
{
    seat /= 2;
    // Modify table creation to include the updated seat value.
    PrivateTable* newTable = new PrivateTable(engine, tableID, seat);
    privateTables.push_back(newTable);
}

#endif