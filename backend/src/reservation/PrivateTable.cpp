#ifndef PRIVATETABLE_CPP
#define PRIVATETABLE_CPP

#include "PrivateTable.h"

PrivateTable::PrivateTable(Engine* engine, int tableID, int seat) : Table(engine, tableID, seat) {}

PrivateTable::~PrivateTable(){}

void PrivateTable::addReservation(ReservationSystem* reservation, int seat)
{
    this->seat = seat;
    this->reservation = reservation;
    isOccupied = true;
}

// void PrivateTable::sendNotification()
// {
//     engine->notify();
// }

// void PrivateTable::receiveNotification(std::string message)
// {
//     engine->receive(message);
// }

#endif