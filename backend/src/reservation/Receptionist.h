#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <memory>

// #include "Customer.h"
// #include "GameComponent.h"
#include "ReservationSystem.h"
#include "Table.h"
#include "PrivateTable.h"
#include "PrivateSection.h"
#include "GeneralSection.h"
#include "GeneralTable.h"

// class Engine;


class Receptionist  {
    private:
        int PRIVATE_TABLE_CAPACITY = 4;
        int GENERAL_TABLE_CAPACITY = 4;
        ReservationSystem* reservation;
        // std::vector<Table*> privateTables;
        // std::vector<Table*> generalTables;
    public:
        Receptionist();
        Receptionist(Engine* engine);
        ~Receptionist();
        void createReservation(int reservationID, int startTime, int numberOfCustomers);
        void showCustomerToTable();
        ReservationSystem* getReservation();
};

#endif