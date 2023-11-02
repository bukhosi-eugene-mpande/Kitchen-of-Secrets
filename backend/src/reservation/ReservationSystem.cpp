#include "ReservationSystem.h"

ReservationSystem::ReservationSystem(int reservationID, int startTime, int numberOfCustomers)
    : reservationID(reservationID), startTime(startTime), numberOfCustomers(numberOfCustomers) 
{}
 
void ReservationSystem::initializeAndPush()
{
    reservations.push_back(shared_from_this());
}

ReservationSystem::~ReservationSystem() {}

std::shared_ptr<ReservationSystem> ReservationSystem::getReservation(int index) {
    return reservations[index];
}

void ReservationSystem::setReservation(std::shared_ptr<ReservationSystem> reservation) {
    reservations.push_back(reservation);
}

std::vector<std::shared_ptr<ReservationSystem>> ReservationSystem::getReservations() {
    return reservations;
}

// Receptionist* ReservationSystem::getReceptionist() {
//     return receptionist;
// }

// void ReservationSystem::setReceptionist(Receptionist* receptionist) {
//     this->receptionist = receptionist;
// }

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


