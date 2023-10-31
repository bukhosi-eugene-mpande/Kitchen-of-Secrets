#include "GeneralTable.h"

GeneralTable::GeneralTable(int tableID, int seat) : Table(tableID, seat) {
    this->tableID = tableID;
}

// GeneralTable::GeneralTable(Engine* engine, int tableI, int seat) : Table(engine, tableID, seat) {}

GeneralTable::~GeneralTable(){}

void GeneralTable::addReservation(ReservationSystem* reservation, int seat){
    this->seat = seat;
    this->reservation = reservation;
    isOccupied = true;
}

int GeneralTable::getSeat()
{
    return this->seat;
}

int GeneralTable::getTableID()
{
    return this->tableID;
}

// void GeneralTable::sendNotification()
// {
//     engine->notify();
// }

// void GeneralTable::receiveNotification(std::string message)
// {
//     engine->receive(message);
// }

void GeneralTable::setSeat(int seat)
{
    this->seat = seat;
}