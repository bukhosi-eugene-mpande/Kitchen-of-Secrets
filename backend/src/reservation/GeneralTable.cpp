#ifdef GENERALTABLE_CPP
#define GENERALTABLE_CPP

#include "GeneralTable.h"

GeneralTable::PrivateTable(Engine* engine, int tableI, int seat) : Table(engine, tableID) {}

GeneralTable::~GeneralTable(){}

void GeneralTable::addReservation(ReservationSystem* reservation, int seat){
    this->seat = seat;
    this->reservation = reservation;
    isOccupied = true;
}

void GeneralTable::sendNotification()
{
    engine->notify();
}

void GeneralTable::receiveNotification(std::string message)
{
    engine->receive(message);
}


#endif