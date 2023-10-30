#ifndef PRIVATETABLE_H
#define PRIVATETABLE_H

#include "Table.h"

class PrivateTable : public Table {
 public:
    PrivateTable(int tableID);
    ~PrivateTable();
    void addReservation();
    void markTableOccupied();
    bool isTableAvailable();
};

#endif