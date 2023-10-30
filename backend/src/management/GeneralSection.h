#ifndef GENERAL_SECTION_H
#define GENERAL_SECTION_H

#include <vector>

#include "SeatingPlan.h"
#include "Customer.h"

class GeneralSection : public SeatingPlan {
        int numberOfSeats;
        std::vector<Customer*> availableSeats;
    public:
        GeneralSection();
        ~GeneralSection();
        virtual void seatCustomers(std::vector<Customer*> customers);
        virtual void combineTables();
        virtual void seperateTables(Table* table1, Table* table2);
};

#endif