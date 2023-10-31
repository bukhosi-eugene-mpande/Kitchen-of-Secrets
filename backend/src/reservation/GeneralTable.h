#ifndef GENERALTABLE_H
#define GENERALTABLE_H

#include "Table.h"
// #include "Engine.h"

class GeneralTable : public Table {
    // int seat;
    // int tableID;
 public:
    GeneralTable(int tableID, int seat);
    // GeneralTable(Engine* engine, int tableID, int seat);
    ~GeneralTable();
    void addReservation(ReservationSystem* reservation, int seat);
    // void sendNotification();
    // void receiveNotification(std::string message);
    void setSeat(int seat);
    int getSeat();
    int getTableID();
};

#endif