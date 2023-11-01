#include <iostream>
#include <memory>
#include <vector>

#include "ReservationSystem.h"
#include "Receptionist.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

using namespace std;

int main() {
    // Create a ReservationSystem
    std::shared_ptr<ReservationSystem> reservation = std::make_shared<ReservationSystem>(1, 10, 4);
    reservation->initializeAndPush();

    // // Create a Receptionist
    Receptionist receptionist; 
    receptionist.createReservation(1, 12, 2);//this createReservation does not work properly. this is seen in the for loop for printing the reservations below.
    receptionist.createReservation(1, 12, 4);

    // Create PrivateSection and GeneralSection
    PrivateSection privateSection(3);
    GeneralSection generalSection(4);

    // Get reservations from ReservationSystem
    std::vector<std::shared_ptr<ReservationSystem>> reservations = reservation->getReservations();

    // Show customers to tables
    receptionist.showCustomerToTable(privateSection, generalSection);

    // Access and manipulate Reservations in ReservationSystem
    std::cout << "Reservations in the system:" << std::endl;
    for (const auto& res : reservations) {
        std::cout << "Reservation ID: " << res->getReservationID() << ", Start Time: " << res->getStartTime()
                  << ", Number of Customers: " << res->getNumberOfCustomers() << std::endl;
    }

    // Access and manipulate PrivateTables in PrivateSection
    std::vector<std::shared_ptr<PrivateTable>> privateTables = privateSection.getPrivateTables();
    std::cout << "Private Tables in the Private Section:" << std::endl;
    for (const auto& table : privateTables) {
        std::cout << "PrivateTable ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }

    // Access and manipulate GeneralTables in GeneralSection
    std::vector<std::shared_ptr<GeneralTable>> generalTables = generalSection.getGeneralTables();
    std::cout << "General Tables in the General Section:" << std::endl;
    for (const auto& table : generalTables) {
        std::cout << "GeneralTable ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }

    // Test combining and separating tables in PrivateSection
    privateSection.combineTables(0, 1); // Combine tables with IDs 0 and 1 -- this works but the table is not removed from the vector
    privateSection.seperateTables(0);    // Separate table with ID 0 -- this works but the table is not removed from the vector

    // Test combining and separating tables in GeneralSection  -- I HAVE NOT UPDATED THE GENERALSECTION COMBINE AND SEPARATE TABLES FUNCTIONS TO LOOK LIKE THE PRIVATE SECTION BC I WAS FIXING THE PRIVATE SECTION COMBINE AND SEPARATE FUNCTIONS.
    generalSection.combineTables(1, 2); // Combine tables with IDs 1 and 2
    generalSection.seperateTables(4);    // Separate table with ID 4

    // Updated table information
    std::cout << "Private Tables in the Private Section (after combining and separating):" << std::endl;
    for (const auto& table : privateTables) {
        std::cout << "PrivateTable ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }

    std::cout << "General Tables in the General Section (after combining and separating):" << std::endl;
    for (const auto& table : generalTables) {
        std::cout << "GeneralTable ID: " << table->getTableID() << ", Seat: " << table->getSeat() << std::endl;
    }

    return 0;
}
