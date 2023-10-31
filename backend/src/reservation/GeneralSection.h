#ifndef GENERALSECTION_H
#define GENERALSECTION_H

#include "SeatingPlan.h"
#include "GeneralTable.h"
// #include "Customer.h"
// class Customer;

class GeneralSection : public SeatingPlan {
    int seat;
    // Customer* customer;
    int capacity;
    std::vector<GeneralTable*> generalTables;
    // Engine* engine;
    int GENERAL_TABLE_CAPACITY = 3;

 public: 
    GeneralSection(int seat);
    GeneralSection();
    ~GeneralSection();
    // void seatCustomers(Customer* customer);
    void combineTables(int tableID1, int tableID2);
    void seperateTables(int tableID);
    std::vector<GeneralTable*> getGeneralTables();
};

#endif
