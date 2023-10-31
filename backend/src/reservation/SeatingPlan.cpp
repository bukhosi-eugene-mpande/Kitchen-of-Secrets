#ifndef SEATPLAN_CPP
#define SEATPLAN_CPP

#include "SeatingPlan.h"

SeatingPlan::SeatingPlan(){}

SeatingPlan::~SeatingPlan(){}

void SeatingPlan::addReservation(ReservationSystem* reservation)
{
    if (table->getIsOccupied()) {
        table->setIsOccupied(true);
    } else {
        std::cout << "Table is not available." << std::endl;
    }
}

#endif