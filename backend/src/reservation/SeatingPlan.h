#ifndef SEATPLAN_H
#define SEATPLAN_H
#include <iostream>
#include <vector>

#include "Table.h"

using namespace std;

class SeatingPlan {
    Table* table;

public:
    SeatingPlan();
    ~SeatingPlan();
    virtual void addReservation(ReservationSystem* reservation);
    virtual void seatCustomers() = 0;
    virtual void combineTables() = 0;
    virtual void seperateTables(Table* table1, Table* table2) = 0;
};

#endif