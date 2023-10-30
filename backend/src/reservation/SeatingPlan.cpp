#ifndef SEATPLAN_CPP
#define SEATPLAN_CPP

#include "SeatingPlan.h"

SeatingPlan::SeatingPlan(){}

SeatingPlan::~SeatingPlan(){}

void SeatingPlan::addReservation()
{
    if (table->isTableAvailable()) {
        table->markTableOccupied();
    } else {
        std::cout << "Table is not available." << std::endl;
    }
}

void SeatingPlan::markTableOccupied()
{
    table->markTableOccupied();
}

bool SeatingPlan::isTableAvailable()
{
    return table->isTableAvailable();
}

#endif