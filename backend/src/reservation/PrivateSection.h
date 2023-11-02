#ifndef PRIVATESECTION_H
#define PRIVATESECTION_H

#include "SeatingPlan.h"
#include "PrivateTable.h"
// #include <memory>
// #include "Customer.h"
// class Customer;

class PrivateSection : public SeatingPlan {
    // Customer* customer;
    std::vector<std::shared_ptr<PrivateTable>> privateTables;
    // Engine* engine;
    const int PRIVATE_TABLE_CAPACITY = 3;

 public: 
    int seat;
    PrivateSection(int seat);
    PrivateSection();
    ~PrivateSection();
    // void seatCustomers(Customer* customer);
    void combineTables(int tableID1, int tableID2);
    void seperateTables(int tableID);
    std::vector<std::shared_ptr<PrivateTable>> getPrivateTables();
};

#endif
