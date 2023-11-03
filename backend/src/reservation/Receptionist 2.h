#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

#include <vector>
#include <iostream>
#include <memory> 

// #include "Customer.h"
// #include "GameComponent.h"
#include "ReservationSystem.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

class Receptionist  {
    private:
        const int PRIVATE_TABLE_CAPACITY = 6;
        const int GENERAL_TABLE_CAPACITY = 12;
        std::shared_ptr<ReservationSystem> reservation;
    public:
        Receptionist();
        // Receptionist(Engine* engine); //this is using josh's system
        ~Receptionist();
        void createReservation(int reservationID, int startTime, int numberOfCustomers);
        void showCustomerToTable(PrivateSection& privateT, GeneralSection& genT);
        std::shared_ptr<ReservationSystem> getReservation();
};

#endif