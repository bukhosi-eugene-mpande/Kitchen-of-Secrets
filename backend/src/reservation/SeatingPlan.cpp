#ifndef SEATPLAN_CPP
#define SEATPLAN_CPP

#include "SeatingPlan.h"

SeatingPlan::SeatingPlan(){}

SeatingPlan::~SeatingPlan(){}

void SeatingPlan::addReservation()
{
    if (table->getIsOccupied()) {
        table->setIsOccupied(true);
    } else {
        std::cout << "Table is not available." << std::endl;
    }
}

#endif