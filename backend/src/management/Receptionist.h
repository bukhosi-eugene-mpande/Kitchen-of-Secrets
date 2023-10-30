#ifndef RECEPTIONIST_H
#define RECEPTIONSIT_H

#include <memory>

#include "Customer.h"
#include "GameComponent.h"
#include "ReservationSystem.h"
#include "Table.h"

class Receptionist : public GameComponent {
    private:
        Reservation* reservation;
        std::vector<Table*> privateTables;
        std::vector<Table*> generalTables;
    public:
        Receptionist(Engine* engine);
        ~Receptionist();
        void createReservation(int reservationID, int startTime, int numberOfCustomers);
        void showCustomerToTable();
};

#endif