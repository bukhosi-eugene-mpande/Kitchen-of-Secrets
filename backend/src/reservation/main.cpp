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
    Engine engine;

    // Create a Receptionist.
    Receptionist receptionist(&engine);

    // Create a ReservationSystem with ID 1, starting time 1, and 4 customers.
    receptionist.createReservation(1, 1, 4);

    // Create a PrivateSection with an initial seat value.
    PrivateSection privateSection(2);

    // Show customers to tables based on reservations.
    receptionist.showCustomerToTable();

    // Combine and separate tables in the PrivateSection.
    std::vector<PrivateTable*> privateTables = privateSection.getPrivateTables();
    privateTables[0]->combineTables(privateTables[0], privateTables[1]); // Example: Combine tables with ID 0 and 1.
    privateSection.seperateTables(privateTables[2]);   // Example: Remove a table with ID 2.

    // Access the privateTables vector and print table information.
    for (PrivateTable* table : privateTables) {
        std::cout << "Table ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }

    return 0;
}
