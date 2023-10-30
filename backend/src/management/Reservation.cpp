#include "Reservation.h"

Reservation::Reservation(int reservationID, int startTime, int numberOfCustomers) {
    this->reservationID = reservationID;
    this->startTime = startTime;
    this->numberOfCustomers = numberOfCustomers;
    setReservation(this);
}

Reservation::~Reservation() {}

Reservation* Reservation::getReservation(int index) {
    return reservations.at(index);
}

void Reservation::setReservation(Reservation* reservation) {
    reservations.push_back(reservation);
}

std::vector<Reservation*> Reservation::getReservations() {
    return reservations;
}

int Reservation::getReservationID() {
    return reservationID;
}

void Reservation::setReservationID(int reservationID) {
    this->reservationID = reservationID;
}

int Reservation::getStartTime() {
    return startTime;
}

void Reservation::setStartTime(int startTime) {
    this->startTime = startTime;
}

int Reservation::getNumberOfCustomers() {
    return numberOfCustomers;
}

void Reservation::setNumberOfCustomers(int numberOfCustomers) {
    this->numberOfCustomers = numberOfCustomers;
}

