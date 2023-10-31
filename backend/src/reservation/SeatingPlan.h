#ifndef SEATPLAN_H
#define SEATPLAN_H
#include <iostream>
#include <vector>

#include "Table.h"
#include "ReservationSystem.h"

class ReservationSystem;

using namespace std;

class SeatingPlan {
    Table* table;

public:
    SeatingPlan();
    ~SeatingPlan();
    virtual void addReservation(ReservationSystem* reservation);
    // virtual void seatCustomers(Customer* customer) = 0;
    virtual void combineTables(int tableID1, int tableID2) = 0;
    virtual void seperateTables(int tableID) = 0;
};

#endif