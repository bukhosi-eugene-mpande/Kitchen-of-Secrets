#ifndef RESERVATION_H
#define RESERVATION_H

#include <vector>
#include <memory> 
#include <iostream>
// #include "Receptionist.h"

class ReservationSystem : public std::enable_shared_from_this<ReservationSystem> {
    private:
        std::vector<std::shared_ptr<ReservationSystem>> reservations = std::vector<std::shared_ptr<ReservationSystem>>();
        int reservationID;
        int startTime;
        int numberOfCustomers;
    public:
        ReservationSystem(int reservationID, int startTime, int numberOfCustomers);
        void initializeAndPush();
        ~ReservationSystem();
        std::shared_ptr<ReservationSystem> getReservation(int index);
        void setReservation(std::shared_ptr<ReservationSystem> reservation);
        std::vector<std::shared_ptr<ReservationSystem>> getReservations();
        int getReservationID();
        void setReservationID(int reservationID);
        int getStartTime();
        void setStartTime(int startTime);
        int getNumberOfCustomers();
        void setNumberOfCustomers(int numberOfCustomers);
};

#endif
