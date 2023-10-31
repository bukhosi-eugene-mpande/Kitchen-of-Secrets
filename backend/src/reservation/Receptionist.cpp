#ifndef RECEPTIONIST_CPP
#define RECEPTIONIST_CPP

#include "Receptionist.h"

Receptionist::Receptionist(Engine* engine)  {}

Receptionist::~Receptionist() {}

void Receptionist::createReservation(int reservationID, int startTime, int numberOfCustomers) {
    ReservationSystem* newReservation = new ReservationSystem(reservationID, startTime, numberOfCustomers);
}

void Receptionist::showCustomerToTable() {
    std::vector<ReservationSystem*> reservations = reservation->getReservations();
    for (ReservationSystem* reservation : reservations) {
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
            assignedTable->addReservation(reservation, numberOfCustomers);
            std::cout << "Assigned reservation #" << reservation->getReservationID() << " to table #" << assignedTable->getTableID() << std::endl;
        } else {
            std::cout << "No available tables for reservation #" << reservation->getReservationID() << std::endl;
        }
    }
}

ReservationSystem *Receptionist::getReservation()
{
    return reservation;
}

#endif