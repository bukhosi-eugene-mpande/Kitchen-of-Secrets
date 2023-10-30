#include "ReservationSystem.h"

ReservationSystem::ReservationSystem() {}

ReservationSystem::~ReservationSystem() {}

Receptionist* ReservationSystem::getReceptionist() {
    return receptionist;
}

void ReservationSystem::setReceptionist(Receptionist* receptionist) {
    this->receptionist = receptionist;
}