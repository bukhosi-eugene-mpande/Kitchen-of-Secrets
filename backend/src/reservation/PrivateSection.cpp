#ifndef PRIVATESECTION_CPP
#define PRIVATESECTION_CPP

#include "PrivateSection.h"

PrivateSection::PrivateSection() : SeatingPlan() {
    seat = 2;
}

PrivateSection::~PrivateSection(){}

void PrivateSection::seatCustomers(Customer *customer)
{
    this->customer = customer;
}

//these functions below have problems. how can i refer to the table in the vector? should i make another table vector? :(
void PrivateSection::combineTables(int tableID)
{
    for (std::iterator* it = privateTables.begin(); it != privateTables.end(); ++it) {
        if ((*it)->getTableID() == tableID) {
            delete *it;
            privateTables.erase(it);
            break;
        }
    }

    // Increase the initial table capacity to double the initial amount.
    seat *= 2;

    // Create a new table with the updated capacity.
    PrivateTable* newTable = new PrivateTable(engine, tableID);
    privateTables.push_back(newTable);
}

void PrivateSection::seperateTables(Table *table1, Table *table2)
{
    for (auto it = privateTables.begin(); it != privateTables.end(); ++it) {
        if ((*it)->getTableID() == tableID) {
            delete *it;
            privateTables.erase(it);
            break;
        }
    }

    // Decrease the initial table capacity to half the initial amount.
    seat /= 2;

    // Create a new table with the updated capacity.
    PrivateTable* newTable = new PrivateTable(engine, tableID);
    privateTables.push_back(newTable);
}

#endif