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

class ReservationSystem;
class PrivateSection;
class GeneralSection;

class Receptionist  {
    private:
        int PRIVATE_TABLE_CAPACITY = 3;
        int GENERAL_TABLE_CAPACITY = 3;
        ReservationSystem* reservation;
        // std::vector<Table*> privateTables;
        // std::vector<Table*> generalTables;
    public:
        Receptionist();
        // Receptionist(Engine* engine);
        ~Receptionist();
        void createReservation(int reservationID, int startTime, int numberOfCustomers);
        void showCustomerToTable(PrivateSection& privateT, GeneralSection& genT);
        ReservationSystem* getReservation();
};

#endif