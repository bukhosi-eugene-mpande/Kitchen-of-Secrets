#ifndef PRIVATETABLE_CPP
#define PRIVATETABLE_CPP

#include "PrivateTable.h"

PrivateTable::PrivateTable(Engine* engine, int tableID) : Table(engine, tableID) {}

PrivateTable::~PrivateTable(){}

void PrivateTable::addReservation()
{
    this->reservation = reservation;
    isOccupied = true;
}

void PrivateTable::sendNotification()
{
    // engine->notify(engine->getCustomer());
}

void PrivateTable::receiveNotification(std::string message)
{
    // engine->receive(message);
}

#endif