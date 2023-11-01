#include "PrivateSection.h"

PrivateSection::PrivateSection(int seat) : SeatingPlan() {
    seat = 2;
    for (int i = 0; i < PRIVATE_TABLE_CAPACITY; ++i) {
        //  std::shared_ptr<PrivateTable> newTable = std::make_shared<PrivateTable>(engine, i, seat); // Initialize tables with the seat value.
        std::shared_ptr<PrivateTable> newTable = std::make_shared<PrivateTable>(i, seat); // Use make_shared
        privateTables.push_back(newTable);
    }
}

PrivateSection::PrivateSection(){}

PrivateSection::~PrivateSection(){}

// void PrivateSection::seatCustomers(Customer *customer)
// {
//     this->customer = customer;
// }

// void PrivateSection::combineTables(int tableID1, int tableID2) //id 1 == deletes table , id2 == table to be combined
// {
//     seat *= 2;
//     for(int i = 0; i < privateTables.size(); i++){
//         if(privateTables[i]->getTableID() == tableID1){
//             privateTables[i]->setSeat(seat);
//         }
//         if(privateTables[i]->getTableID() == tableID2){
//             privateTables.erase(privateTables.begin() + i);
//         }
//     }
//     std::cout << "Table " << tableID1 << " has been combined with table " << tableID2 << " and has this information-- " << privateTables[1]->getSeat() << ::endl;
// }

void PrivateSection::combineTables(int tableID1, int tableID2) {
    // Find the tables with the specified IDs
    std::shared_ptr<PrivateTable> tableToCombine = nullptr;
    std::shared_ptr<PrivateTable> tableToDelete = nullptr;

    for (int i = 0; i < privateTables.size(); i++) {
        if (privateTables[i]->getTableID() == tableID1) {
            tableToCombine = privateTables[i];
        }
        if (privateTables[i]->getTableID() == tableID2) {
            tableToDelete = privateTables[i];
            int index = i;
        }
    }

    // Check if both tables were found
    if (tableToCombine && tableToDelete) {
        // Check if both tables are unoccupied
        if (!tableToCombine->getIsOccupied() && !tableToDelete->getIsOccupied()) {
            // Perform the table combination
            int newSeat = tableToCombine->getSeat() * 2;
            tableToCombine->setSeat(newSeat);

        privateTables.erase(std::remove_if(
            privateTables.begin(),
            privateTables.end(),
            [&tableToDelete](const std::shared_ptr<PrivateTable>& table) {
                return table == tableToDelete;
            }
        ), privateTables.end());
    } else {
            // Tables are occupied, or one of them doesn't exist
            std::cout << "Tables cannot be combined because they are occupied." << std::endl;
        }
    } else {
        // One or both tables were not found
        std::cout << "One or both tables specified do not exist." << std::endl;
    }
}

void PrivateSection::seperateTables(int tableID) {
    seat /= 2;
    bool tableFound = false;  // Flag to indicate if the specified table was found and separated

    for (auto it = privateTables.begin(); it != privateTables.end();) {
        if ((*it)->getTableID() == tableID) {
            // Check if the table is unoccupied
            if (!(*it)->getIsOccupied()) {
                it = privateTables.erase(it);  // Remove the table from the vector
                tableFound = true;  // Set the flag to true
            } else {
                std::cout << "Table " << tableID << " is occupied and cannot be separated." << std::endl;
                ++it;  // Move to the next table
            }
        } else {
            ++it;  // Move to the next table
        }
    }

    if (tableFound) {
        // Create new tables if the specified table was found and separated
        int newid1 = static_cast<int>(privateTables.size());
        int newid2 = newid1 + 1;
        std::shared_ptr<PrivateTable> newTable = std::make_shared<PrivateTable>(newid1, seat);
        std::shared_ptr<PrivateTable> newTable2 = std::make_shared<PrivateTable>(newid2, seat);
        privateTables.push_back(newTable);
        privateTables.push_back(newTable2);
    } else {
        std::cout << "Table " << tableID << " not found or not separated." << std::endl;
    }
}

std::vector<std::shared_ptr<PrivateTable>> PrivateSection::getPrivateTables() {
    return privateTables;
}