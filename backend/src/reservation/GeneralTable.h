#ifndef GENERALTABLE_H
#define GENERALTABLE_H

#include "Table.h"

class GeneralTable : public Table {
 public:
    GeneralTable(int tableID);
    ~GeneralTable();
    void addReservation();
    void markTableOccupied();
    bool isTableAvailable();
};

#endif