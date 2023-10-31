#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include "Receptionist.h"

class ReservationSystem {
    private:
        std::vector<ReservationSystem*> reservations;
        int reservationID;
        int startTime;
        int numberOfCustomers;
    public:
        ReservationSystem(int reservationID, int startTime, int numberOfCustomers);
        ~ReservationSystem();
        ReservationSystem* getReservation(int index);
        void setReservation(ReservationSystem* reservation);
        std::vector<ReservationSystem*> getReservations();
        int getReservationID();
        void setReservationID(int reservationID);
        int getStartTime();
        void setStartTime(int startTime);
        int getNumberOfCustomers();
        void setNumberOfCustomers(int numberOfCustomers);
};

#endif
