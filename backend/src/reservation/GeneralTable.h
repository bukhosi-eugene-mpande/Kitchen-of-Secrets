#ifndef GENERALTABLE_H
#define GENERALTABLE_H

#include "Table.h"
#include "Engine.h"

class GeneralTable : public Table {
 public:
    GeneralTable(Engine* engine, int tableID);
    ~GeneralTable();
    void addReservation(ReservationSystem* reservation);
    void sendNotification();
    void receiveNotification(std::string message);
};

#endif