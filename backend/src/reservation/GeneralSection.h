#ifndef GENERALSECTION_H
#define GENERALSECTION_H

#include "SeatingPlan.h"
#include "GeneralTable.h"
// #include "Customer.h"
// #include "Engine.h"

class GeneralSection : public SeatingPlan {
    int seat;
    // Customer* customer; //from chenoa's system
    // Engine* engine; //from josh's system
    int capacity;
    std::vector<std::shared_ptr<GeneralTable>> generalTables;
    const int GENERAL_TABLE_CAPACITY = 3;

 public: 
    GeneralSection(int seat);
    GeneralSection();
    ~GeneralSection();
    // void seatCustomers(Customer* customer);
    void combineTables(int tableID1, int tableID2);
    void seperateTables(int tableID);
    std::vector<std::shared_ptr<GeneralTable>> getGeneralTables();
};

#endif
