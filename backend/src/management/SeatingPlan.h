#ifndef SEATING_PLAN_H
#define SEATING_PLAN_H

#include "Table.h"

#include <memory>

class SeatingPlan {
    public:
        SeatingPlan();
        ~SeatingPlan();
        virtual void seatCustomers() = 0;
        virtual void combineTables() = 0;
        virtual void seperateTables(Table* table1, Table* table2) = 0;
};

#endif

