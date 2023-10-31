#ifdef GENERALTABLE_CPP
#define GENERALTABLE_CPP

#include "GeneralTable.h"

GeneralTable::PrivateTable(Engine* engine, int tableID) : Table(engine, tableID) {}

GeneralTable::~GeneralTable(){}

void GeneralTable::addReservation(ReservationSystem* reservation){
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