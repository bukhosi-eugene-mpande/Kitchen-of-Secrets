#ifndef PRIVATESECTION_H
#define PRIVATESECTION_H

#include "SeatingPlan.h"
// #include "Customer.h"

class PrivateSection : public SeatingPlan {
    int seat;
    Customer* customer;
 public: 
    PrivateSection();
    ~PrivateSection();
    void seatCustomers(Customer* customer);
    void combineTables();
    void seperateTables(Table* table1, Table* table2);
};

#endif
