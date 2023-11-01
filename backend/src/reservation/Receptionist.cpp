#include "Receptionist.h"

Receptionist::Receptionist(std::shared_ptr<ReservationSystem> reservationSystem)  {
    this->reservationSystem = reservationSystem;
}

Receptionist::~Receptionist() {

}

