#ifndef PRIVATETABLE_H
#define PRIVATETABLE_H

#include "Table.h"
// #include "Engine.h"

class PrivateTable : public Table {
 private: 
    int seat;
 public:
    PrivateTable(Engine* engine, int tableID, int seat);
    ~PrivateTable();
    void addReservation(ReservationSystem* reservation, int seat);
    void setSeat(int seat);
    // void sendNotification();
    // void receiveNotification(std::string message);
};

#endif