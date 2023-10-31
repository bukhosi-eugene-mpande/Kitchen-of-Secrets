#ifndef GENERALSECTION_H
#define GENERALSECTION_H

#include "SeatingPlan.h"
// #include "Customer.h"

class GeneralSection : public SeatingPlan {
    int seat;
    Customer* customer;
    int capacity;
 public: 
    GeneralSection();
    ~GeneralSection();
    virtual void seatCustomers(Customer* customer);
    virtual void combineTables();
    virtual void seperateTables(Table* table1, Table* table2);
};

#endif
