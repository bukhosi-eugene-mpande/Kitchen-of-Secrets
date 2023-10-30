#ifndef RESERVATION_SYSTEM_H
#define RESERVATION_SYSTEM_H

#include <memory>

#include "Reservation.h"
#include "Receptionist.h"

class ReservationSystem {
    private:
        Reservation* reservation;
        Receptionist* receptionist;
    public:
        ReservationSystem();
        ~ReservationSystem();
        Receptionist* getReceptionist();
        void setReceptionist(Receptionist* receptionist);
};

#endif