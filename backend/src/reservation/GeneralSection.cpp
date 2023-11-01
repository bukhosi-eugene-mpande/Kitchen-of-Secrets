#include "GeneralSection.h"

GeneralSection::GeneralSection(int seat) : SeatingPlan() {
    seat = 4;
    for (int i = 0; i < GENERAL_TABLE_CAPACITY; ++i) {
        // std::shared_ptr<GeneralTable> newTable = std::make_shared<GeneralTable>(engine, i, seat); // Initialize tables with the seat value.
        std::shared_ptr<GeneralTable> newTable = std::make_shared<GeneralTable>(i, seat); // Use make_shared
        generalTables.push_back(newTable);
    }
}

GeneralSection::GeneralSection(){}

GeneralSection::~GeneralSection() {}

// void GeneralSection::seatCustomers(std::shared_ptr<Customer> customer) {
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
    for (size_t i = 0; i < generalTables.size(); ++i) {
        if (generalTables[i]->getTableID() == tableID) {
            generalTables.erase(generalTables.begin() + i);
        }
    }
    int newid1 = static_cast<int>(generalTables.size()) + 1;
    int newid2 = static_cast<int>(generalTables.size()) + 2;
    std::shared_ptr<GeneralTable> newTable = std::make_shared<GeneralTable>(newid1, seat);
    std::shared_ptr<GeneralTable> newTable2 = std::make_shared<GeneralTable>(newid2, seat);
    // std::shared_ptr<GeneralTable> newTable = std::make_shared<GeneralTable>(engine,newid1, seat); 
    // std::shared_ptr<GeneralTable> newTable2 = std::make_shared<GeneralTable>(engine,newid2, seat);
    generalTables.push_back(newTable);
    generalTables.push_back(newTable2);
}

std::vector<std::shared_ptr<GeneralTable>> GeneralSection::getGeneralTables() {
    return generalTables;
}
