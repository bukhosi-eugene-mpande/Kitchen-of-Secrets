#include "GeneralSection.h"

GeneralSection::GeneralSection(int seat) : SeatingPlan() {
    seat = 4;
    for (int i = 0; i < GENERAL_TABLE_CAPACITY; ++i) {
        // GeneralTable* newTable = new GeneralTable(engine, i, seat); // Initialize tables with the seat value.
        GeneralTable* newTable = new GeneralTable(i, seat); // Initialize tables with the seat value.
        generalTables.push_back(newTable);
    }
}

GeneralSection::GeneralSection(){}

GeneralSection::~GeneralSection() {}

// void GeneralSection::seatCustomers(Customer* customer) {
//    this->customer = customer;
// }

void GeneralSection::combineTables(int tableID1, int tableID2) //id 1 == table to be combined , id2 == table to be deleted
{
    seat *= 2;
    for(int i = 0; i < generalTables.size(); i++){
        if(generalTables[i]->getTableID() == tableID1){
            generalTables[i]->setSeat(seat);
        }
        if(generalTables[i]->getTableID() == tableID2){
            generalTables.erase(generalTables.begin() + i);
        }
    }
}

void GeneralSection::seperateTables(int tableID)
{
    seat /= 2;
    for(int i = 0; i < generalTables.size(); i++){
        if(generalTables[i]->getTableID() == tableID){
            generalTables.erase(generalTables.begin() + i);
        }
    }
    int newid1 = generalTables.size() + 1;
    int newid2 = generalTables.size() + 2;
    // GeneralTable* newTable = new GeneralTable(engine,newid1, seat); 
    // GeneralTable* newTable2 = new GeneralTable(engine,newid2, seat);
    GeneralTable* newTable = new GeneralTable(newid1, seat); 
    GeneralTable* newTable2 = new GeneralTable(newid2, seat);
    generalTables.push_back(newTable);
    generalTables.push_back(newTable2);
}

std::vector<GeneralTable*> GeneralSection::getGeneralTables() {
    return generalTables;
}
