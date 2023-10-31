#include "PrivateSection.h"

PrivateSection::PrivateSection(int seat) : SeatingPlan() {
    seat = 2;
    // this->seat = seat;
    for (int i = 0; i < PRIVATE_TABLE_CAPACITY; ++i) {
        // PrivateTable* newTable = new PrivateTable(engine, i, seat); // Initialize tables with the seat value.
        PrivateTable* newTable = new PrivateTable(i, seat); // Initialize tables with the seat value.
        privateTables.push_back(newTable);
    }
}

PrivateSection::PrivateSection(){}

PrivateSection::~PrivateSection(){}

// void PrivateSection::seatCustomers(Customer *customer)
// {
//     this->customer = customer;
// }

void PrivateSection::combineTables(int tableID1, int tableID2) //id 1 == deletes table , id2 == table to be combined
{
    seat *= 2;
    for(int i = 0; i < privateTables.size(); i++){
        if(privateTables[i]->getTableID() == tableID1){
            privateTables[i]->setSeat(seat);
        }
        if(privateTables[i]->getTableID() == tableID2){
            privateTables.erase(privateTables.begin() + i);
        }
    }
}

void PrivateSection::seperateTables(int tableID)
{
    seat /= 2;
    for(int i = 0; i < privateTables.size(); i++){
        if(privateTables[i]->getTableID() == tableID){
            privateTables.erase(privateTables.begin() + i);
        }
    }
    int newid1 = privateTables.size() + 1;
    int newid2 = privateTables.size() + 2;
    // PrivateTable* newTable = new PrivateTable(engine,newid1, seat); 
    // PrivateTable* newTable2 = new PrivateTable(engine,newid2, seat);
    PrivateTable* newTable = new PrivateTable(newid1, seat); 
    PrivateTable* newTable2 = new PrivateTable(newid2, seat);
    privateTables.push_back(newTable);
    privateTables.push_back(newTable2);
}

std::vector<PrivateTable*> PrivateSection::getPrivateTables() {
    return privateTables;
}