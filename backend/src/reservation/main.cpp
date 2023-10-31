#include <iostream>
#include <vector>
#include "Receptionist.h"
#include "ReservationSystem.h"
#include "Table.h"
#include "PrivateTable.h"
#include "GeneralTable.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

int main() {
    // Engine engine;

    // Create a Receptionist.
    // Receptionist receptionist(&engine);
    Receptionist receptionist;

    // Create a ReservationSystem with ID 1, starting time 1, and 2 customers.
    receptionist.createReservation(1, 1, 2);

    receptionist.getReservation();
    // // Create a PrivateSection with an initial seat value.
    PrivateSection privateSection(2);

    // // Create a GeneralSection.
    GeneralSection generalSection(4);

    

    // // Show customers to tables based on reservations.
    receptionist.showCustomerToTable(privateSection, generalSection);

    // Access the privateTables vector and print table information.
    for (PrivateTable* table : privateSection.getPrivateTables()) {
        std::cout << "Private Table ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }
    
    // // Combine and separate tables in the PrivateSection.
    // // std::vector<PrivateTable*> privateTables = privateSection.getPrivateTables();
    // // privateTables.combineTables(0, 1); // Example: Combine tables with ID 0 and 1.
    // privateSection.combineTables(0, 1); // Example: Combine tables with ID 0 and 1.
    // privateSection.seperateTables(2);   // Example: Remove a table with ID 2.

    // // Access the privateTables vector and print updated table information.
    // for (PrivateTable* table : privateSection.getPrivateTables()) {
    //     std::cout << "Private Table ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    // }

    return 0;
}
