#ifndef GENERALSECTION_CPP
#define GENERALSECTION_CPP

#include "GeneralSection.h"

GeneralSection::GeneralSection() : SeatingPlan() {
    seat = 4;
}

GeneralSection::~GeneralSection() {}

void GeneralSection::seatCustomers(Customer* customer) {
    // if (customers.size() > numberOfSeats) {
        
    // } else {
    //     std::vector<Customer*>::iterator availableCustomers = customers.begin();
    //     std::vector<Customer*>::iterator seatingIndex = availableSeats.begin();
    //     for (seatingIndex; seatingIndex < availableSeats.end(); seatingIndex++) {
    //         *seatingIndex = *availableCustomers;
    //         availableCustomers++;
    //     }
    // }
    this->customer = customer;
}

void GeneralSection::combineTables()
{
    
}

void GeneralSection::seperateTables(Table *table1, Table *table2)
{
    
}


#endif