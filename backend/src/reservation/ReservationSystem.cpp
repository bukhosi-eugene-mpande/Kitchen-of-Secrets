#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(int reservationID, int startTime, int numberOfCustomers)
{
    this->reservationID = reservationID;
    this->startTime = startTime;
    this->numberOfCustomers = numberOfCustomers;
    reservations.push_back(this);
}

ReservationSystem::~ReservationSystem() {}

ReservationSystem *ReservationSystem::getReservation(int index)
{
    return reservations[index];
}

void ReservationSystem::setReservation(ReservationSystem *reservation)
{
    reservations.push_back(reservation);
}

// Receptionist* ReservationSystem::getReceptionist() {
//     return receptionist;
// }

// void ReservationSystem::setReceptionist(Receptionist* receptionist) {
//     this->receptionist = receptionist;
// }

std::vector<ReservationSystem*> ReservationSystem::getReservations()
{
    return reservations;
}

int ReservationSystem::getReservationID()
{
    return reservationID;
}

void ReservationSystem::setReservationID(int reservationID)
{
    this->reservationID = reservationID;
}

int ReservationSystem::getStartTime()
{
    return startTime;
}

void ReservationSystem::setStartTime(int startTime)
{
    this->startTime = startTime;
}

int ReservationSystem::getNumberOfCustomers()
{
    return numberOfCustomers;
}

void ReservationSystem::setNumberOfCustomers(int numberOfCustomers)
{
    this->numberOfCustomers = numberOfCustomers;
}


