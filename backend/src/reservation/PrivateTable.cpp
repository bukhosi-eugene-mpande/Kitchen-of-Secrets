#include "PrivateTable.h"

PrivateTable::PrivateTable(int tableID, int seat) : Table(tableID, seat) {
    // this->tableID = tableID;
}

// PrivateTable::PrivateTable(Engine* engine, int tableID, int seat) : Table(engine, tableID, seat) {}

PrivateTable::PrivateTable(){}

PrivateTable::~PrivateTable(){}

void PrivateTable::addReservation(std::shared_ptr<ReservationSystem> reservation, int seat)
{
    // this->seat = seat;
    this->reservation = reservation;
    isOccupied = true;
}

int PrivateTable::getSeat()
{
    return this->seat;
}

int PrivateTable::getTableID()
{
    return this->tableID;
}

void PrivateTable::setSeat(int seatv)
{
    seat = seatv;
}

// void PrivateTable::sendNotification()
// {
//     engine->notify();
// }

// void PrivateTable::receiveNotification(std::string message)
// {
//     engine->receive(message);
// }
