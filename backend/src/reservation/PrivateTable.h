#ifndef PRIVATETABLE_H
#define PRIVATETABLE_H

#include "Table.h"
#include "Engine.h"

class PrivateTable : public Table {
 public:
    PrivateTable(Engine* engine, int tableID);
    ~PrivateTable();
    void addReservation(ReservationSystem* reservation);
    void sendNotification();
    void receiveNotification(std::string message);
};

#endif