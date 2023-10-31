#ifndef GENERALTABLE_H
#define GENERALTABLE_H

#include "Table.h"
#include "Engine.h"

class GeneralTable : public Table {
    int seat;
 public:
    GeneralTable(Engine* engine, int tableID, int seat);
    ~GeneralTable();
    void addReservation(ReservationSystem* reservation, int seat);
    void sendNotification();
    void receiveNotification(std::string message);
};

#endif