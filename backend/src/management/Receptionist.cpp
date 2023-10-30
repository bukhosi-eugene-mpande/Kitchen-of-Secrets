#include "Receptionist.h"

Receptionist::Receptionist(Engine* engine) : GameComponent(engine) {}

Receptionist::~Receptionist() {}

void Receptionist::createReservation(int reservationID, int startTime, int numberOfCustomers) {
    Reservation* newReservation = new Reservation(reservationID, startTime, numberOfCustomers);
}

void Receptionist::showCustomerToTable() {
    std::vector<Reservation*> reservations = reservation->getReservations();
    for (Reservation* reservation : reservations) {
        int numberOfCustomers = reservation->getNumberOfCustomers();
        Table* assignedTable = nullptr;
        if (numberOfCustomers <= PRIVATE_TABLE_CAPACITY && !privateTables.empty()) {
            assignedTable = privateTables.back();
            privateTables.pop_back();
        }
        else if (!generalTables.empty()) {
            assignedTable = generalTables.back();
            generalTables.pop_back();
        }

        if (assignedTable) {
            assignedTable->assignReservation(reservation);
            std::cout << "Assigned reservation #" << reservation->getReservationID() << " to table #" << assignedTable->getTableID() << std::endl;
        } else {
            std::cout << "No available tables for reservation #" << reservation->getReservationID() << std::endl;
        }
    }
}
