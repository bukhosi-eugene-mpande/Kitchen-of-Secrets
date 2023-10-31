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

    // Create a receptionist to manage reservations and tables
    Receptionist receptionist(&engine);

    // Create tables for the restaurant
    PrivateTable privateTable1(&engine, 1);
    PrivateTable privateTable2(&engine, 2);
    GeneralTable generalTable1(&engine, 3);
    GeneralTable generalTable2(&engine, 4);

    // Create seating sections
    PrivateSection privateSection;
    GeneralSection generalSection;

    // Assign tables to sections
    privateSection.addTable(&privateTable1);
    privateSection.addTable(&privateTable2);
    generalSection.addTable(&generalTable1);
    generalSection.addTable(&generalTable2);

    // Create reservations
    receptionist.createReservation(1, 18, 4);
    receptionist.createReservation(2, 19, 2);

    // Simulate customers being shown to tables
    receptionist.showCustomerToTable();

    // Simulate customers placing orders
    privateTable1.placeTable(1, 1);
    privateTable1.addReservation(ReservationSystem::getReservation(0));
    privateTable1.receiveNotification("Customer is ready to order.");

    generalTable1.placeTable(2, 2);
    generalTable1.addReservation(ReservationSystem::getReservation(1));
    generalTable1.receiveNotification("Customer is ready to order.");

    // Simulate combining tables
    privateSection.combineTables(1);

    // Simulate separating tables
    privateSection.separateTables(1, 3);
    
    return 0;
}
