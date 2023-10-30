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
    virtual void addReservation();
    virtual void markTableOccupied();
    virtual bool isTableAvailable();
};

#endif