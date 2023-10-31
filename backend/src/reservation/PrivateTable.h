#ifndef PRIVATETABLE_H
#define PRIVATETABLE_H

#include "Table.h"
// #include "Engine.h"

class PrivateTable : public Table {
 private: 
    int seat;
 public:
    PrivateTable(int tableID, int seat);
   //  PrivateTable(Engine* engine, int tableID, int seat);
    PrivateTable();
    ~PrivateTable();
    void addReservation(ReservationSystem* reservation, int seat);
    void setSeat(int seat);
   int getSeat();
    // void sendNotification();
    // void receiveNotification(std::string message);
};

#endif