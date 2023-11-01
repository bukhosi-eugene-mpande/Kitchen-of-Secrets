#include "Receptionist.h"

Receptionist::Receptionist()  {}
// Receptionist::Receptionist(Engine* engine)  {}

Receptionist::~Receptionist() {}

void Receptionist::createReservation(int reservationID, int startTime, int numberOfCustomers) {
    reservation = std::make_shared<ReservationSystem>(reservationID, startTime, numberOfCustomers);
    reservation->initializeAndPush();
}

void Receptionist::showCustomerToTable(PrivateSection& privateT, GeneralSection& genT) {
    std::vector<std::shared_ptr<ReservationSystem>> reservations = reservation->getReservations();

    for (std::shared_ptr<ReservationSystem>& res : reservations) {
        int numberOfCustomers = res->getNumberOfCustomers();
        std::shared_ptr<Table> assignedTable = nullptr;

        if (numberOfCustomers <= PRIVATE_TABLE_CAPACITY && !privateT.getPrivateTables().empty()) {
            assignedTable = privateT.getPrivateTables().back();
            privateT.getPrivateTables().pop_back();
            if (assignedTable) {
                if (numberOfCustomers > 2)
                    assignedTable->addReservation(res, numberOfCustomers);
                std::cout << assignedTable->getTableID() << std::endl;
            } else {
                std::cout << "No available tables for reservation #" << res->getReservationID() << std::endl;
            }
        }
        else if (!genT.getGeneralTables().empty()) {
            assignedTable = genT.getGeneralTables().back();
            genT.getGeneralTables().pop_back();
        }
    }
}


std::shared_ptr<ReservationSystem> Receptionist::getReservation()
{
    return reservation;
}

