#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H

// #include <memory>
#include <vector>
#include <iostream>

// #include "Customer.h"
// #include "GameComponent.h"
#include "ReservationSystem.h"
#include "PrivateSection.h"
#include "GeneralSection.h"

// class ReservationSystem;
// class PrivateSection;
// class GeneralSection;

class Receptionist  {
    private:
        int PRIVATE_TABLE_CAPACITY = 6;
        int GENERAL_TABLE_CAPACITY = 12;
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