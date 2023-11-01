#include "Receptionist.h"

#include "Reservation.h"
#include "../customercare/Customer.h"
#include "Host.h"
#include "ReservationSystem.h"

Receptionist::Receptionist(std::shared_ptr<ReservationSystem> reservationSystem)  {
    this->reservationSystem = reservationSystem;
}

Receptionist::~Receptionist() {

}

