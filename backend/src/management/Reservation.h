#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
    private:
        std::vector<Reservation*> reservations;
        int reservationID;
        int startTime;
        int numberOfCustomers;
    public:
        Reservation(int reservationID, int startTime, int numberOfCustomers);
        ~Reservation();
        Reservation* getReservation(int index);
        void setReservation(Reservation* reservation);
        std::vector<Reservation*> getReservations();
        int getReservationID();
        void setReservationID(int reservationID);
        int getStartTime();
        void setStartTime(int startTime);
        int getNumberOfCustomers();
        void setNumberOfCustomers(int numberOfCustomers);
};

#endif

