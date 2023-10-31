#ifndef PRIVATETABLE_CPP
#define PRIVATETABLE_CPP

#include "PrivateTable.h"

PrivateTable::PrivateTable(int tableID, int seat) : Table(tableID, seat) {}

// PrivateTable::PrivateTable(Engine* engine, int tableID, int seat) : Table(engine, tableID, seat) {}

PrivateTable::PrivateTable(){}

PrivateTable::~PrivateTable(){}

void PrivateTable::addReservation(ReservationSystem* reservation, int seat)
{
    this->seat = seat;
    this->reservation = reservation;
    isOccupied = true;
}

int PrivateTable::getSeat()
{
    return this->seat;
}

void PrivateTable::setSeat(int seat)
{
    this->seat = seat;
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