#ifndef PRIVATE_SECTION_H
#define PRIVATE_SECTION_H

#include "SeatingPlan.h"
#include "Customer.h"

class PrivateSection : public SeatingPlan {
        int seat;
        Customer* customer;
    public:
        PrivateSection();
        ~PrivateSection();
        virtual void seatCustomers(Customer* customer);
        virtual void combineTables();
        virtual void seperateTables(Table* table1, Table* table2);
};

#endif