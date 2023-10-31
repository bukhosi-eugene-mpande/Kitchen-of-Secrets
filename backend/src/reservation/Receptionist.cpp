#include "Receptionist.h"

Receptionist::Receptionist()  {}
// Receptionist::Receptionist(Engine* engine)  {}

Receptionist::~Receptionist() {}

void Receptionist::createReservation(int reservationID, int startTime, int numberOfCustomers) {
    reservation = new ReservationSystem(reservationID, startTime, numberOfCustomers);
}

void Receptionist::showCustomerToTable(PrivateSection& privateT, GeneralSection& genT) {
    std::vector<ReservationSystem*> reservations = reservation->getReservations();
    
    for (ReservationSystem* res : reservations) {
        int numberOfCustomers = res->getNumberOfCustomers();
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
            assignedTable->addReservation(res, numberOfCustomers);
            std::cout << assignedTable->getTableID() << std::endl;
            // std::cout << "Assigned reservation #" << res->getReservationID() << " to table #" << assignedTable->getTableID() << std::endl;
        } else {
            std::cout << "No available tables for reservation #" << res->getReservationID() << std::endl;
        }
    }
}


ReservationSystem *Receptionist::getReservation()
{
    return reservation;
}

