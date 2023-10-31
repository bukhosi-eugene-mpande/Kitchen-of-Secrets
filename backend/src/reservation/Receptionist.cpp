#ifndef RECEPTIONIST_CPP
#define RECEPTIONIST_CPP

#include "Receptionist.h"

Receptionist::Receptionist()  {}
// Receptionist::Receptionist(Engine* engine)  {}

Receptionist::~Receptionist() {}

void Receptionist::createReservation(int reservationID, int startTime, int numberOfCustomers) {
    ReservationSystem* newReservation = new ReservationSystem(reservationID, startTime, numberOfCustomers);
}

void Receptionist::showCustomerToTable() {
    PrivateSection privateT;
    GeneralSection genT;
    
    std::vector<ReservationSystem*> reservations = reservation->getReservations();
    for (ReservationSystem* reservation : reservations) {
        int numberOfCustomers = reservation->getNumberOfCustomers();
        Table* assignedTable = nullptr;
        if (numberOfCustomers <= PRIVATE_TABLE_CAPACITY && !privateT.getPrivateTables().empty()) {
            assignedTable = privateT.getPrivateTables().back();
            privateT.getPrivateTables().pop_back();
        }
        else if (!genT.getGeneralTables().empty()) {
            assignedTable = genT.getGeneralTables().back();
            genT.getGeneralTables().pop_back();
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